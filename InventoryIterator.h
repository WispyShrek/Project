#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Iterator.h"
#include "Inventory.h"

class InventoryIterator : public Iterator<Inventory*> {
  public:
    Inventory* currItem() override;
    void first() override;
    bool isDone() override;
    void next() override;
    void prev() override;
};

#endif
