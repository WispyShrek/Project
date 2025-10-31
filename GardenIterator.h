#ifndef GARDENITERATOR_H
#define GARDENITERATOR_H

#include "Iterator.h"
#include <vector>

class Garden;

/**
 * @class GardenIterator
 * @brief Iterator for traversing a collection of Garden pointers.
 *
 * This iterator provides bidirectional traversal over a std::vector<Garden*>
 * with standard operations to get the current item, move to the first/next/previous
 * elements, and query completion.
 */
class GardenIterator : public Iterator<Garden*> {
  public:
    /**
     * @fn GardenIterator::GardenIterator
     * @brief Constructs an iterator over the provided gardens collection.
     * @param gardens Reference to the underlying vector of Garden pointers.
     */
    GardenIterator(std::vector<Garden*>& gardens);

    /**
     * @fn GardenIterator::currItem
     * @brief Returns the current Garden pointer.
     * @return Pointer to the current Garden, or nullptr if the iterator is done.
     */
    Garden* currItem() override;

    /**
     * @fn GardenIterator::first
     * @brief Positions the iterator at the first element.
     *
     * After calling this, isDone() will be false if the collection is non-empty,
     * otherwise it will remain true for an empty collection.
     */
    void first() override;

    /**
     * @fn GardenIterator::isDone
     * @brief Checks whether the iterator has reached the end.
     * @retval [true] if there is no current item (past the last element or empty)
     * @retval [false] if there is a current item.
     */
    bool isDone() override;

    /**
     * @fn GardenIterator::next
     * @brief Advances the iterator to the next element if not done.
     *
     * If the iterator is already done, calling this has no effect.
     */
    void next() override;

    /**
     * @fn GardenIterator::prev
     * @brief Moves the iterator to the previous element if possible.
     *
     * If the iterator is at the first element, calling this has no effect.
     */
    void prev() override;

  private:
    std::size_t currentIndex;
    std::vector<Garden*>& gardens;
};

#endif // GARDENITERATOR_H