#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H
#include <iostream>

#include "Staff.h"
#include <queue>
#include <vector>
#include "Customer.h"
class Garden;
class PlantCaretaker : public Staff {
private:
  std::queue<Garden *> careQueue;
  std::vector<Customer *> custList;
public:
  PlantCaretaker();
  /*! @fn void PlantCaretaker::care()
   * @brief Applies care to gardens.
   * The care function dequeues a garden pointer the from the front of the
   * careQueue member variable and calls applyCare() on the dequeued object.
   * Only one object gets dequeued per function call. When the careQueue is
   * empty the function will have no effect.
   */
  void care() override;
  /*! @fn void PlantCaretaker::update(Garden *subjectOfCare)
   * @brief Adds new garden to careQueue.
   * The update function takes a the input parameter and pushes it to the
   * back of the careQueue member variable without calling any functions on
   * the parameter.
   *
   * @param A pointer to a Garden object.
   */
    void update(Garden *subjectOfCare);

    ~PlantCaretaker();
};

#endif
