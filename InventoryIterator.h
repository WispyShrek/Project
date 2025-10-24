#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Iterator.h"
#include "Inventory.h"
#include <vector>
#include <string>
#include <iostream>

class InventoryIterator : public Iterator<std::string> {
  public:
    InventoryIterator(std::vector<std::string> & items);
    std::string currItem() override;
    void first() override;
    bool isDone() override;
    void next() override;
    void prev() override;
  private:
    std::size_t currentIndex;
    std::vector<std::string> items;
};

#endif
