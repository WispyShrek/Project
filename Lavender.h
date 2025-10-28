#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"
#include "PartialSunCare.h"

class Lavender : public Plant {

public:
  Lavender();
  std::string getName();
  Lavender *clone();
  void print() override;

protected:
  Lavender(Lavender &toCopy);
};

#endif
