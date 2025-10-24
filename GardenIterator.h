#ifndef GARDENITERATOR_H
#define GARDENITERATOR_H
#include "Garden.h"
#include "Iterator.h"

class GardenIterator : public Iterator<Garden *> {
  public:
    Garden *currItem() override;
    void first() override;
    bool isDone() override;
    void next() override;
    void prev() override;
};

#endif
