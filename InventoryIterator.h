#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Iterator.h"
template <typename T>

class InventoryIterator : public Iterator<T> {
public:
  T currItem();
  void first();
  bool isDone();
  void next();
  void prev();
};

#endif
