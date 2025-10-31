#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Iterator.h"
#include <iostream>
#include "Plant.h"
#include <vector>

class Plant;

class PlantIterator : public Iterator<Plant*> {
public:
    /*! @fn PlantIterator::PlantIterator(std::vector<std::vector<Plant*>>& grid)
     * @brief Constructs an iterator over a 3x3 Plant* grid.
     * @param grid Reference to the 3x3 grid. The grid must outlive the iterator.
     */
    PlantIterator(std::vector<std::vector<Plant*>>& grid);

    /*! @fn Plant* PlantIterator::currItem()
     * @brief Returns the current plant pointer or nullptr if done.
     */
    Plant* currItem() override;

    /*! @fn void PlantIterator::first()
     * @brief Positions to the first non-null plant in the grid.
     */
    void first() override;

    /*! @fn bool PlantIterator::isDone()
     * @brief True if there is no current non-null plant to point to.
     */
    bool isDone() override;

    /*! @fn void PlantIterator::next()
     * @brief Advances to the next non-null plant; stays done if none.
     */
    void next() override;

    /*! @fn void PlantIterator::prev()
     * @brief Moves to the previous non-null plant; stays if at first.
     */
    void prev() override;

private:
    std::vector<std::vector<Plant*>>& grid;
    // linear index in [0, 8]; use npos to represent "done/no valid"
    static constexpr std::size_t npos = static_cast<std::size_t>(-1);
    std::size_t idx; // current linear index into 3x3 grid or npos

    std::size_t rows() const;
    std::size_t cols() const;
    Plant* at(std::size_t linear) const;
    std::size_t findNext(std::size_t start) const;
    std::size_t findPrev(std::size_t start) const;
};

#endif
