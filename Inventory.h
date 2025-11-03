#ifndef INVENTORY_H
#define INVENTORY_H

#include "Collection.h"
#include "InventoryIterator.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class Inventory
 * @brief Manages a collection of inventory items as strings.
 *
 * The Inventory class implements the Collection interface for string items,
 * providing functionality to add, remove, and iterate over inventory items.
 * Items are stored in order of addition with no capacity limit.
 */
class Inventory : public Collection<std::string> {
  public:
    /*! @fn void Inventory::addItem(std::string item)
     * @brief Adds an item to the inventory.
     *
     * Appends the given string to the end of the inventory collection.
     * Duplicate items are allowed and will be stored separately.
     *
     * @param item The name of the item to add to the inventory.
     */
    void addItem(std::string item) override;
    
    /*! @fn Iterator<std::string>* Inventory::CreateIterator()
     * @brief Creates an iterator for the inventory collection.
     *
     * Returns a new InventoryIterator that allows traversal of the inventory items.
     * The caller is responsible for deleting the returned iterator when finished.
     *
     * @return A pointer to a newly created Iterator<std::string> object.
     */
    Iterator<std::string> *CreateIterator() override;
    
    /*! @fn void Inventory::removeItem(std::string item)
     * @brief Removes the first occurrence of an item from the inventory.
     *
     * Searches for the given item name in the inventory and removes the first
     * matching occurrence. If the item is not found, the function has no effect.
     * If there are duplicate items, only the first one is removed.
     *
     * @param item The name of the item to remove from the inventory.
     */
    void removeItem(std::string item) override;
    
  private:
    std::vector<std::string> inventoryItems;
};

#endif
