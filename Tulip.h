#ifndef TULIP_H
#define TULIP_H

#include "Plant.h"
#include "ShadyCare.h"

class Tulip : public Plant {
public:
  Tulip();
  std::string getName();
  Tulip *clone();
  void print() override;

  double getPrice();

protected:
  Tulip(Tulip &toCopy);

private:
  double price;
};

#endif
