#include "Garden.h"
#include "PlantCaretaker.h"
#include <algorithm>

Garden::~Garden(){
    // Clean up all plants
    for(Plant* plant : plants){
        delete plant;
    }
    plants.clear();
}

void Garden::addItem(Plant *item){
    if(plantCount <= 6){
        plants.push_back(item);
        plantCount++;
    }else{
      std::cout << "Garden is full, cannot add more plants." << std::endl;
    }
}

Iterator<Plant *> *Garden::CreateIterator(){
    return new PlantIterator(plants);
}

void Garden::removeItem(Plant *item){
    auto it = std::find(plants.begin(), plants.end(), item);
    if(it != plants.end()){
        plants.erase(it);
        plantCount--;
    }
}

void Garden::TemplateMethod() {}

void Garden::applyCare() {}

void Garden::attach(PlantCaretaker *staff) { this->staffList.push_back(staff); }

void Garden::detach(PlantCaretaker *staff) {
  this->staffList.erase(std::find(staffList.begin(), staffList.end(), staff));
}

void Garden::notify() {
  for (auto plantCaretaker : staffList) {
    plantCaretaker->update(this);
  }
}
