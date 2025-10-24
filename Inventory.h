#ifndef INVENTORY_H
#define INVENTORY_H

#include "Collection.h"
#include "InventoryIterator.h"
#include <iostream>
#include <string>
#include <vector>

class Inventory : public Collection<std::string> {
  public:
    //the methods used for the iterator DP, the concrete methods.
    void addItem(std::string item) override;
    Iterator<std::string> *CreateIterator() override;
    void removeItem(std::string item) override;
  private:
    std::vector<std::string> inventoryItems;


};

#endif
