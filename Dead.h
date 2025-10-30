#ifndef DEAD_H
#define DEAD_H

#include "Plant.h"
#include "PlantState.h"

class Dead : public PlantState {
public:
  void next(Plant *context);
  void print();
  PlantState* clone() const override;
};
 
#endif