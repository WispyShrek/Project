#include "GreenhouseIterator.h"

GreenhouseIterator::GreenhouseIterator(std::vector<greenHouse *> &greenHouses): currentIndex(0), greenHouses(greenHouses){
}

greenHouse *GreenhouseIterator::currItem(){
    if(!isDone()){
        return greenHouses[currentIndex];
    }else{
        return nullptr;
    }
}

void GreenhouseIterator::first(){
    currentIndex = 0;
}

bool GreenhouseIterator::isDone(){
    return currentIndex >= greenHouses.size();
}

void GreenhouseIterator::next(){
    if(!isDone()){
        ++currentIndex;
    }
}

void GreenhouseIterator::prev(){
    if(currentIndex > 0){
        --currentIndex;
    }
}
