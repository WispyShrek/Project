#include "PlantIterator.h"

PlantIterator::PlantIterator(std::vector<Plant *> &plants) :currentIndex(0), plants(plants){
}

Plant *PlantIterator::currItem(){
    if(!isDone()){
        return plants[currentIndex];
    }else{
        return nullptr;
    }
}

void PlantIterator::first()
{
    currentIndex = 0;
}

bool PlantIterator::isDone(){
    return currentIndex >= plants.size();
}

void PlantIterator::next() {
  if(!isDone()){
      ++currentIndex;
  }
}

void PlantIterator::prev() {
  if(currentIndex > 0){
      --currentIndex;
  }
}
