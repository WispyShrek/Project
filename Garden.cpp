#include "Garden.h"

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

void Garden::attach(Staff *staff) {}

void Garden::detach(Staff *staff) {}

void Garden::notify() {}
