#include "GardenIterator.h"

GardenIterator::GardenIterator(std::vector<Plant *> &plants) :currentIndex(0), plants(plants){
}

Plant *GardenIterator::currItem(){
    if(!isDone()){
        return plants[currentIndex];
    }else{
        return nullptr;
    }
}

void GardenIterator::first()
{
    currentIndex = 0;
}

bool GardenIterator::isDone(){
    return currentIndex >= plants.size();
}

void GardenIterator::next() {
  if(!isDone()){
      ++currentIndex;
  }
}

void GardenIterator::prev() {
  if(currentIndex > 0){
      --currentIndex;
  }
}
