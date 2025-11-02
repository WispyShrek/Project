#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "Collection.h"
#include "Plant.h"
#include "PlantIterator.h"
#include <vector>

/** @class greenHouse
 * @brief A class representing a greenhouse that holds a 3x3 grid of plants.
 *
 * The greenHouse class inherits from the Collection<Plant*> class and
 * implements methods to manage a 3x3 grid of Plant pointers, including adding,
 * removing, and iterating over the plants in the greenhouse.
 */

class greenHouse : public Collection<Plant *> {
private:
  std::vector<std::vector<Plant *>> plants =
      std::vector<std::vector<Plant *>>(3, std::vector<Plant *>(3, nullptr));
  int plantCount = 0;

public:
  /** @fn @greenHouse::greenHouse()
   * @brief Constructor for greenHouse class.
   */
  ~greenHouse();
  /** @fn void greenHouse::powerSystem()
   * @brief Powers the greenhouse system, toggling sprinklers and lights on or
   * off.
   */
  void powerSystem();

  /*! @fn Iterator<Plant*> *greenHouse::CreateIterator()
   * @brief Creates an iterator over the 3x3 plant grid (row-major, skips
   * nulls).
   * @return A pointer to a newly created Iterator<Plant*> object.
   */
  Iterator<Plant *> *CreateIterator() override;

  /*! @fn bool greenHouse::tryAddItem(Plant *item)
   * @brief Adds a plant to the first available slot in the 3x3 grid and returns
   * true upon success. If 9 plants already exist, the plant is not added and
   * returns false.
   * @param[in] item A pointer to a Plant object to be added to the greenhouse.
   * @return a boolean representing successful addition.
   */
  bool tryAddItem(Plant *item) override;

  /*! @fn void greenHouse::addItem(Plant *item, int row, int col)
   * @brief Adds a plant at a specific grid position (if empty and within
   * bounds). Enforces the same 7-plant capacity as Garden.
   * @param[in] item Plant to add
   * @param[in] row Row index in [0..2]
   * @param[in] col Column index in [0..2]
   */
  void addItem(Plant *item, int row, int col);

  /*! @fn void greenHouse::removeItem(Plant *item)
   * @brief Removes the first matching plant pointer from the grid (sets cell to
   * nullptr). Decrements plantCount on success. Does not delete the Plant
   * object.
   * @param[in] item A pointer to the Plant object to be removed.
   */
  void removeItem(Plant *item) override;
};

#endif
