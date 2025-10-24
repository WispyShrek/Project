#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Iterator.h"
template <typename T>

class InventoryIterator : public Iterator<T> {
  public:
    T currItem() override;
    void first() override;
    bool isDone() override;
    void next() override;
    void prev() override;
};

#endif
