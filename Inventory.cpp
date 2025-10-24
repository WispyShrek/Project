#include "Inventory.h"

void Inventory::addItem(std::string item){
    inventoryItems.push_back(item);
}

Iterator<std::string> *Inventory::CreateIterator(){
    return new InventoryIterator(inventoryItems);
}

void Inventory::removeItem(std::string item){
}
