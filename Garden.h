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
   * The addItem function adds the given Plant pointer to the plants vector
   * if the garden has not reached its maximum capacity of 7 plants. If the
   * garden is full, an error message is printed and the plant is not added.
   * The plantCount is incremented when a plant is successfully added.
   * @param[in] item A pointer to a Plant object to be added to the garden.
   */
  void addItem(Plant *item);
  
  /*! @fn Iterator<Plant *> *Garden::CreateIterator()
   * @brief Creates an iterator for the garden's plant collection.
   * The CreateIterator function returns a new PlantIterator object that
   * allows traversal of the plants vector. The caller is responsible for
   * deleting the returned iterator when finished.
   * @return A pointer to a newly created Iterator<Plant *> object.
   */
  Iterator<Plant *> *CreateIterator();
  
  /*! @fn void Garden::removeItem(Plant *item)
   * @brief Removes a plant from the garden.
   * The removeItem function searches for the given Plant pointer in the
   * plants vector and removes the first occurrence if found. The plantCount
   * is decremented when a plant is successfully removed. If the plant is not
   * found in the garden, the function has no effect. Note that this function
   * does not delete the Plant object; the caller is responsible for managing
   * the plant's memory after removal.
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
  std::vector<Plant *> plants;
  int plantCount = 0;
};

#endif
