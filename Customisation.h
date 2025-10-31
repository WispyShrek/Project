#ifndef CUSTOMISATION_H
#define CUSTOMISATION_H
#include "Plant.h"

class Customisation : public Plant {

public:
  Plant *plant;
  virtual void increasePrice() = 0;
  virtual void addCust(Customer *customer) = 0;
};

#endif
