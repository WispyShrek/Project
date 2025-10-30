#include "Garden.h"
#include "PlantCaretaker.h"
#include "Rose.h"
#include "Sunny.h"
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

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Garden::addItem adds plants to garden") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();
    
    garden.addItem(p1);
    garden.addItem(p2);
    garden.addItem(p3);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == false);
    CHECK(it->currItem() == p1);
    it->next();
    CHECK(it->currItem() == p2);
    it->next();
    CHECK(it->currItem() == p3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
}

TEST_CASE("Garden::addItem respects maximum capacity of 7 plants") {
    Sunny garden;
    
    std::vector<Plant*> plants;
    for(int i = 0; i < 8; i++){
        plants.push_back(new Rose());
    }
    
    // Add 7 plants (should succeed)
    for(int i = 0; i < 7; i++){
        garden.addItem(plants[i]);
    }
    
    // Try to add 8th plant (should fail)
    garden.addItem(plants[7]);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    int count = 0;
    while(!it->isDone()){
        count++;
        it->next();
    }
    
    CHECK(count == 7);
    
    delete it;
    delete plants[7]; // The 8th plant wasn't added, so we need to delete it
}

TEST_CASE("Garden::removeItem removes specified plant") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();
    
    garden.addItem(p1);
    garden.addItem(p2);
    garden.addItem(p3);
    
    garden.removeItem(p2);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == p1);
    it->next();
    CHECK(it->currItem() == p3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete p2; // We need to manually delete removed plants
}

TEST_CASE("Garden::removeItem handles non-existent plant") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();
    
    garden.addItem(p1);
    garden.addItem(p2);
    
    garden.removeItem(p3); // p3 was never added
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == p1);
    it->next();
    CHECK(it->currItem() == p2);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete p3;
}

TEST_CASE("Garden::removeItem on empty garden does nothing") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    
    garden.removeItem(p1);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == true);
    
    delete it;
    delete p1;
}

TEST_CASE("Garden::CreateIterator returns valid iterator for empty garden") {
    Sunny garden;
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == true);
    CHECK(it->currItem() == nullptr);
    
    delete it;
}

TEST_CASE("Garden::CreateIterator allows multiple iterations") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    
    garden.addItem(p1);
    garden.addItem(p2);
    
    Iterator<Plant*>* it1 = garden.CreateIterator();
    Iterator<Plant*>* it2 = garden.CreateIterator();
    
    it1->first();
    it2->first();
    
    CHECK(it1->currItem() == p1);
    CHECK(it2->currItem() == p1);
    
    it1->next();
    CHECK(it1->currItem() == p2);
    CHECK(it2->currItem() == p1);
    
    delete it1;
    delete it2;
}

TEST_CASE("Garden operations sequence: add, remove, add") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();
    
    garden.addItem(p1);
    garden.addItem(p2);
    garden.removeItem(p1);
    garden.addItem(p3);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == p2);
    it->next();
    CHECK(it->currItem() == p3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete p1; // Manually delete removed plant
}

TEST_CASE("Garden::removeItem decrements plant count") {
    Sunny garden;
    
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    
    garden.addItem(p1);
    garden.addItem(p2);
    
    garden.removeItem(p1);
    
    // Add another plant to verify count is correct
    Plant* p3 = new Rose();
    garden.addItem(p3);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    int count = 0;
    while(!it->isDone()){
        count++;
        it->next();
    }
    
    CHECK(count == 2);
    
    delete it;
    delete p1;
}

TEST_CASE("Garden can add plants after removing to capacity") {
    Sunny garden;
    
    std::vector<Plant*> plants;
    for(int i = 0; i < 7; i++){
        plants.push_back(new Rose());
        garden.addItem(plants[i]);
    }
    
    // Garden is full, remove one
    garden.removeItem(plants[3]);
    
    // Should be able to add another
    Plant* newPlant = new Rose();
    garden.addItem(newPlant);
    
    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();
    
    int count = 0;
    while(!it->isDone()){
        count++;
        it->next();
    }
    
    CHECK(count == 7);
    
    delete it;
    delete plants[3];
}

#endif // ENABLE_DOCTESTS
