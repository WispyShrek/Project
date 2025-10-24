#ifndef INVENTORY_H
#define INVENTORY_H

#include "Collection.h"

template <typename T>

class Inventory : public Collection<T> {
  public:
    //the methods used for the iterator DP, the concrete methods.
      void addItem(T item) override;
    Iterator<T> *CreateIterator() override;
    T getCurrItem() override;
    bool isEmpty() override;
    void removeItem(T item) override;
};

#endif
