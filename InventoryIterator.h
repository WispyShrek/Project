#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "Inventory.h"
#include "Iterator.h"
#include <iostream>

/**
 * @class InventoryIterator
 * @brief Iterator for traversing a collection of inventory item strings.
 *
 * This iterator provides bidirectional traversal over a std::vector<std::string>
 * with standard operations to get the current item, move to the first/next/previous
 * elements, and query completion.
 */
class InventoryIterator : public Iterator<std::string> {
  public:
    /*! @fn InventoryIterator::InventoryIterator(std::vector<std::string>& items)
     * @brief Constructs an iterator over the provided items collection.
     * @param items Reference to the underlying vector of item name strings.
     *        The caller must ensure the lifetime of this vector outlives the iterator.
     */
    InventoryIterator(std::vector<std::string> & items);
    
    /*! @fn std::string InventoryIterator::currItem()
     * @brief Returns the current item string.
     *
     * If the iterator is done (past the end or empty collection), prints an error
     * message and returns an empty string.
     *
     * @return The current item name, or an empty string if the iterator is done.
     */
    std::string currItem() override;
    
    /*! @fn void InventoryIterator::first()
     * @brief Positions the iterator at the first element.
     *
     * After calling this, isDone() will be false if the collection is non-empty,
     * otherwise it will remain true for an empty collection.
     */
    void first() override;
    
    /*! @fn bool InventoryIterator::isDone()
     * @brief Checks whether the iterator has reached the end.
     * @return true if there is no current item (past the last element or empty), false otherwise.
     */
    bool isDone() override;
    
    /*! @fn void InventoryIterator::next()
     * @brief Advances the iterator to the next element if not done.
     *
     * If the iterator is already done, calling this has no effect.
     */
    void next() override;
    
    /*! @fn void InventoryIterator::prev()
     * @brief Moves the iterator to the previous element if possible.
     *
     * If the iterator is at the first element, calling this has no effect.
     */
    void prev() override;
    
  private:
    std::size_t currentIndex;
    std::vector<std::string> items;
};

#endif
