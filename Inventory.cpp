#include "Inventory.h"

bool Inventory::addItem(std::string item) {
  inventoryItems.push_back(item);
  return true;
}

Iterator<std::string> *Inventory::CreateIterator() {
  return new InventoryIterator(inventoryItems);
}

void Inventory::removeItem(std::string item) {
  for (auto it = inventoryItems.begin(); it != inventoryItems.end(); ++it) {
    if (*it == item) {
      inventoryItems.erase(it);
      return;
    }
  }
}
