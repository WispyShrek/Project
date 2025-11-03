#ifndef SALESFLOOR_H
#define SALESFLOOR_H
#include "Customer.h"
#include "Inventory.h"
#include <vector>
class Customer;

class SalesFloor {
public:
  virtual bool notify(Customer *customer, Plant *plant) = 0;
  SalesFloor() {}
  virtual ~SalesFloor() = default;
  Inventory *getInventory(size_t index) {
    if (index < inventories.size()) {
      return inventories[index];
    }
    return nullptr;
  }
  void addInventory(Inventory *inventory) { inventories.push_back(inventory); }
  void addToPlantInventory(Plant *plant) { plantInventory.push_back(plant); }

private:
  std::vector<Plant *> plantInventory;
  std::vector<Inventory *> inventories;
};

#endif
