#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "GardenIterator.h"
#include "Plant.h"
#include <vector>

class PlantCaretaker;

class Garden : public Collection<Plant *> {
private:
  std::vector<PlantCaretaker *> staffList;

public:
  /*! @fn virtual ~Garden()
   * @brief deallocates a garden object
   * Deletes all plants belonging to the garden and clears the staffList of the
   * garden
   */
  virtual ~Garden();
  // virtual void Print() = 0;
  /*! @fn bool addItem(Plant* item)
   *@brief adds a plant to the garden object
   *The addItem function attempts to find an open position in which to add the
   * given plant object. If no space is found for the plant, the function will
   * return false. The function will return true if the plant could be added.
   *@param A pointer to a plant object
   */

  bool addItem(Plant *item);
  Iterator<Plant *> *CreateIterator();
  /*! @fn void removeItem(Plant* item)
   *@brief removes a plant from the garden object
   *The removeItem function finds and removes the given plant object
   *from the garden by deleting the plant from the plants member variable
   *of the garden object.
   *@param A pointer to a plant object
   *If the given plant is not within the garden the function will have no effect
   */
  void removeItem(Plant *item);
  /*! @fn virtual void applyRays()=0
   *@brief pure virtual function implemented in concrete classes.
   *Concrete function implementations will iterate through plants in a garden,
   *affecting plants that have the matching CareStrategy positively, and other
   *all other plants negatively.
   */
  virtual void applyRays() = 0;
  const std::vector<PlantCaretaker *> &getStaff();
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
};

#endif
