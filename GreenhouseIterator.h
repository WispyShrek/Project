#ifndef GREENHOUSEITERATOR_H
#define GREENHOUSEITERATOR_H
#include "Iterator.h"
#include <vector>

class greenHouse;

/**
 * @class GreenhouseIterator
 * @brief Iterator for traversing a collection of greenHouse pointers.
 *
 * This iterator provides bidirectional traversal over a std::vector<greenHouse*>
 * with standard operations to get the current item, move to the first/next/previous
 * elements, and query completion.
 */
class GreenhouseIterator : public Iterator<greenHouse*>{
    public:
        /*! @fn GreenhouseIterator::GreenhouseIterator(std::vector<greenHouse*>& greenHouses)
         * @brief Constructs an iterator over the provided greenhouses collection.
         * @param greenHouses Reference to the underlying vector of greenHouse pointers.
         *        The caller must ensure the lifetime of this vector outlives the iterator.
         */
        GreenhouseIterator(std::vector<greenHouse*>& greenHouses);
        
        /*! @fn greenHouse* GreenhouseIterator::currItem()
         * @brief Returns the current greenHouse pointer.
         * @return Pointer to the current greenHouse, or nullptr if the iterator is done.
         */
        greenHouse* currItem() override;
        
        /*! @fn void GreenhouseIterator::first()
         * @brief Positions the iterator at the first element.
         *
         * After calling this, isDone() will be false if the collection is non-empty,
         * otherwise it will remain true for an empty collection.
         */
        void first() override;
        
        /*! @fn bool GreenhouseIterator::isDone()
         * @brief Checks whether the iterator has reached the end.
         * @return true if there is no current item (past the last element or empty), false otherwise.
         */
        bool isDone() override;
        
        /*! @fn void GreenhouseIterator::next()
         * @brief Advances the iterator to the next element if not done.
         *
         * If the iterator is already done, calling this has no effect.
         */
        void next() override;
        
        /*! @fn void GreenhouseIterator::prev()
         * @brief Moves the iterator to the previous element if possible.
         *
         * If the iterator is at the first element, calling this has no effect.
         */
        void prev() override;
        
    private:
        std::size_t currentIndex;
        std::vector<greenHouse*>& greenHouses;
};

#endif // GREENHOUSEITERATOR_H