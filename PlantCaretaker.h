#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H

#include "Staff.h"

class PlantCaretaker : public Staff {
public:
  PlantCaretaker();
  void care();
  void update();
  void notify(Customer* customer) override;
};

#endif
