#ifndef MATURE_H
#define MATURE_H

#include "Plant.h"
#include "PlantState.h"

class Mature : public PlantState {
public:
  void next(Plant *context);
};

#endif
