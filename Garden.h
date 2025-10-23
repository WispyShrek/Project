#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "PlantCaretaker.h"
#include <vector>

class Garden : Collection<Garden *> {
private:
  std::vector<PlantCaretaker *> staffList;

public:
  virtual void Print() = 0;
  void addItem(Garden *item);
  Iterator<Garden *> *CreateIterator();
  Garden *getCurrItem();
  bool isEmpty();
  void removeItem(Garden *item);
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
};

#endif
