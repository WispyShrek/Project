#include "GardenIterator.h"

GardenIterator::GardenIterator(std::vector<Garden *> &gardens) : currentIndex(0), gardens(gardens){
}

Garden *GardenIterator::currItem(){
    if(!isDone()){
        return gardens[currentIndex];
    }else{
        return nullptr;
    }
}

void GardenIterator::first(){
    currentIndex = 0;
}

bool GardenIterator::isDone(){
    return currentIndex >= gardens.size();
}

void GardenIterator::next(){
    if(!isDone()){
        ++currentIndex;
    }
}

void GardenIterator::prev(){
    if(currentIndex > 0){
        --currentIndex;
    }
}
