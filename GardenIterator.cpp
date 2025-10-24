#include "GardenIterator.h"

GardenIterator::GardenIterator(std::vector<Garden *> &gardens) : gardens(gardens), currentIndex(0){
}

Garden *GardenIterator::currItem()
{
    if (!isDone()){
        return gardens[currentIndex];
    }else{
        std::cout << "No current item, iterator is done." << std::endl;
        return nullptr;
    }
}

void GardenIterator::first() {
  currentIndex = 0;
}

bool GardenIterator::isDone() {
  return currentIndex >= gardens.size();
}

void GardenIterator::next() {
  if(!isDone()){
      currentIndex++;
  }
}

void GardenIterator::prev() {
  if(currentIndex > 0){
      currentIndex--;
  }
}
