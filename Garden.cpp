#include "Garden.h"
#include <algorithm>

Garden::~Garden(){
    // Clean up all plants
    for(Plant* plant : plants){
        delete plant;
    }
    plants.clear();
}

void Garden::addItem(Plant *item)
{
    plants.push_back(item);
}

Iterator<Plant *> *Garden::CreateIterator(){
    return new GardenIterator(plants);
}

void Garden::removeItem(Plant *item){

}

void Garden::TemplateMethod() {}

void Garden::applyCare() {}

void Garden::attach(PlantCaretaker *staff) { this->staffList.push_back(staff); }

void Garden::detach(PlantCaretaker *staff) {
  this->staffList.erase(std::find(staffList.begin(), staffList.end(), staff));
}

void Garden::notify() {
  for (auto staff : staffList) {
    staff->update(this);
  }
}
