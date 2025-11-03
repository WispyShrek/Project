#include "Inventory.h"

/**
 * @brief Adds an item to the back of the inventory list.
 * @param item The string item to add.
 */
void Inventory::addItem(std::string item){
    inventoryItems.push_back(item);
}

/**
 * @brief Creates an iterator for traversing the inventory items.
 *
 * This method is part of the Iterator design pattern. It returns a new
 * `InventoryIterator` that can be used to iterate over the items in the inventory.
 * @return A pointer to a new `Iterator<std::string>` object. The caller is responsible for deleting this iterator.
 */
Iterator<std::string> *Inventory::CreateIterator(){
    return new InventoryIterator(inventoryItems);
}

/**
 * @brief Removes the first occurrence of a specified item from the inventory.
 *
 * This method iterates through the inventory and removes the first element
 * that matches the given item string. If the item is not found, the inventory remains unchanged.
 * @param item The string item to remove.
 */
void Inventory::removeItem(std::string item){
      for(auto it = inventoryItems.begin(); it != inventoryItems.end(); ++it){
        if(*it == item){
            inventoryItems.erase(it);
            return;
        }
    }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Inventory::addItem adds items to inventory") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("fertilizer");
    inv.addItem("water");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == false);
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->currItem() == "fertilizer");
    it->next();
    CHECK(it->currItem() == "water");
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
}

TEST_CASE("Inventory::addItem handles duplicate items") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("seeds");
    inv.addItem("fertilizer");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->currItem() == "fertilizer");
    
    delete it;
}

TEST_CASE("Inventory::removeItem removes first occurrence of item") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("fertilizer");
    inv.addItem("water");
    
    inv.removeItem("fertilizer");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->currItem() == "water");
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
}

TEST_CASE("Inventory::removeItem handles non-existent item") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("fertilizer");
    
    inv.removeItem("nonexistent");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->currItem() == "fertilizer");
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
}

TEST_CASE("Inventory::removeItem on empty inventory does nothing") {
    Inventory inv;
    
    inv.removeItem("seeds");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == true);
    
    delete it;
}

TEST_CASE("Inventory::removeItem removes only first duplicate") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("seeds");
    inv.addItem("seeds");
    
    inv.removeItem("seeds");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->currItem() == "seeds");
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
}

TEST_CASE("Inventory::CreateIterator returns valid iterator for empty inventory") {
    Inventory inv;
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == true);
    CHECK(it->currItem() == std::string());
    
    delete it;
}

TEST_CASE("Inventory::CreateIterator allows multiple iterations") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("fertilizer");
    
    Iterator<std::string>* it1 = inv.CreateIterator();
    Iterator<std::string>* it2 = inv.CreateIterator();
    
    it1->first();
    it2->first();
    
    CHECK(it1->currItem() == "seeds");
    CHECK(it2->currItem() == "seeds");
    
    it1->next();
    CHECK(it1->currItem() == "fertilizer");
    CHECK(it2->currItem() == "seeds");
    
    delete it1;
    delete it2;
}

TEST_CASE("Inventory operations sequence: add, remove, add") {
    Inventory inv;
    
    inv.addItem("seeds");
    inv.addItem("fertilizer");
    inv.removeItem("seeds");
    inv.addItem("water");
    
    Iterator<std::string>* it = inv.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == "fertilizer");
    it->next();
    CHECK(it->currItem() == "water");
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
}

#endif // ENABLE_DOCTESTS
