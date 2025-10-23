#ifndef DYING_H
#define DYING_H
#include "Plant.h"
#include "PlantState.h"

class Dying : public PlantState {
public:
  void next(Plant *context);
  void prev(Plant *context);
};

#endif
