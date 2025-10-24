#ifndef GARDENITERATOR_H
#define GARDENITERATOR_H

#include "Iterator.h"
#include <iostream>
#include <vector>

class Plant;

class GardenIterator : public Iterator<Plant*> {
  public:
    GardenIterator(std::vector<Plant*>& plants);
    Plant* currItem() override;
    void first() override;
    bool isDone() override;
    void next() override;
    void prev() override;
  private:
    std::size_t currentIndex;
    std::vector<Plant*>& plants;
};

#endif
