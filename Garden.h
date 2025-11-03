#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "PlantIterator.h"
#include "Plant.h"
#include <vector>

class PlantCaretaker;

class Garden : public Collection<Plant *> {
private:
  std::vector<PlantCaretaker *> staffList;

public:
  virtual ~Garden();
  //virtual void Print() = 0;

  /*! @fn void Garden::addItem(Plant *item)
   * @brief Adds a plant to the garden.
   * Adds the plant into the first available slot in the 3x3 grid (row-major).
   * If the grid is full (7+ capacity policy preserved via plantCount), the
   * plant is not added and a message is printed.
   * @param[in] item A pointer to a Plant object to be added to the garden.
   */
  void addItem(Plant *item);

  /*! @fn void Garden::addItem(Plant *item, int row, int col)
   * @brief Adds a plant at a specific grid position.
   * Places the plant at [row][col] if within bounds [0..2] and the cell is empty.
   * If the position is invalid or occupied, the plant is not added.
   * @param[in] item Plant to add
   * @param[in] row Row index in [0..2]
   * @param[in] col Column index in [0..2]
   */
  void addItem(Plant *item, int row, int col);
  
  /*! @fn Iterator<Plant *> *Garden::CreateIterator()
   * @brief Creates an iterator for the garden's plant collection.
   * Returns a PlantIterator that iterates all non-null plants in row-major order.
   * Caller must delete the returned iterator when done.
   * @return A pointer to a newly created Iterator<Plant *> object.
   */
  Iterator<Plant *> *CreateIterator();
  
  /*! @fn void Garden::removeItem(Plant *item)
   * @brief Removes a plant from the garden.
   * Searches the 3x3 grid for the given Plant pointer and nulls that cell if found.
   * Decrements plantCount on success. Does not delete the Plant object.
   * @param[in] item A pointer to the Plant object to be removed from the garden.
   */
  void removeItem(Plant *item);

  void TemplateMethod();
  virtual void applyRays() = 0;
  void applyCare();
  /*! @fn void Garden::attach(PlantCaretaker *staff)
   * @brief Attaches a plantcaretaker to a garden object.
   * The attach function appends the given PlantCaretaker to the staffList
   * member variable for the purpose of being notified of changes to the Garden
   * object.
   * @param A pointer to a PlantCaretaker object.
   */
  void attach(PlantCaretaker *staff);
  /*! @fn void Garden::detach(PlantCaretaker *staff)
   * @brief detaches a plantcaretaker from a garden object.
   * The detach function finds and removes the given PlantCaretaker from the
   * list of PlantCaretakers stored in the staffList member variable to be
   * notified of changes to a Garden object. The given PlantCaretaker
   * will no longer be notified of changes to the Garden object. When the
   * function is called on an empty staffList or the given PlantCaretaker object
   * does not exist within the list, the function will have no effect.
   * @param A pointer to a PlantCaretaker object.
   */
  void detach(PlantCaretaker *staff);
  /*! @fn void Garden::notify()
   * @brief Notifies plantCaretakers of an event.
   * The detach function iterates through the staffList member variable and
   * calls update on each of the PlantCaretaker objects within, using the Garden
   * object calling the function as input parameter.
   * @see PlantCaretaker::update(Garden * subjectOfCare) for details of the
   * update function invoked
   */
  void notify();

private:
  std::vector<std::vector<Plant *>> plants = std::vector<std::vector<Plant *>>(3, std::vector<Plant *>(3, nullptr));
  int plantCount = 0;
};

#endif
