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
  double getPrice();

protected:
  Lavender(Lavender &toCopy);

private:
  double price;
};

#endif
