#ifndef GARDENITERATOR_H
#define GARDENITERATOR_H

#include "Iterator.h"
#include <vector>

class Garden;

class GardenIterator : public Iterator<Garden*> {
  public:
    GardenIterator(std::vector<Garden*>& gardens);
    Garden* currItem() override;
    void first() override;
    bool isDone() override;
    void next() override;
    void prev() override;
  private:
    std::size_t currentIndex;
    std::vector<Garden*>& gardens;
};


#endif // GARDENITERATOR_H