#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Inventory.h"
#include "Iterator.h"
#include <iostream>
#include <string>
#include <vector>

class InventoryIterator : public Iterator<std::string> {
public:
  InventoryIterator(std::vector<std::string> &items);
  std::string currItem() override;
  void first() override;
  bool isDone() override;
  void next() override;
  void prev() override;
  void setCurrItem(std::string string) override {};

private:
  std::size_t currentIndex;
  std::vector<std::string> items;
};

#endif
