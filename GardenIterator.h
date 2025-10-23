#ifndef GARDENITERATOR_H
#define GARDENITERATOR_H
#include "Garden.h"
#include "Iterator.h"

class GardenIterator : public Iterator<Garden *> {
public:
  Garden *currItem();
  void first();
  bool isDone();
  void next();
  void prev();
};

#endif
