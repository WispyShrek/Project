#ifndef SPROUT_H
#define SPROUT_H

#include "Plant.h"
#include "PlantState.h"

class Sprout : public PlantState {
public:
  Sprout() { this->name = "Sprout"; }
  void next(Plant *context) override;
  void print(std::string &sprite) override;
  PlantState *clone() const override;
};

#endif
