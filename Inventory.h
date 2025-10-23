#ifndef INVENTORY_H
#define INVENTORY_H

#include "Collection.h"

template <typename T>

class Inventory : public Collection<T> {

public:
  void addItem(T item);
  Iterator<T> *CreateIterator();
  T getCurrItem();
  bool isEmpty();
  void removeItem(T item);
};

#endif
