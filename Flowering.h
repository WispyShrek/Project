#ifndef FLOWERING_H
#define FLOWERING_H
#include "Plant.h"
#include "PlantState.h"

class Flowering : public PlantState {
public:
  void next(Plant *context);
  void print();
  PlantState* clone() const override;
};

#endif
