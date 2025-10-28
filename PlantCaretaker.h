#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H

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
  ~PlantCaretaker();
  void care();
  void update(Garden *subjectOfCare);
};

#endif
