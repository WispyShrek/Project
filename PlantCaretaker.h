#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H

#include "Staff.h"
#include <queue>

class Garden;

class PlantCaretaker : public Staff {
private:
  std::queue<Garden *> careQueue;

public:
  PlantCaretaker();
  ~PlantCaretaker();
  void care();
  void update(Garden *subjectOfCare);
};

#endif
