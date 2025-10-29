#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include "SunnyCare.h"
class Rose : public Plant {
public:
  Rose();
  std::string getName();
  Rose *clone();
  void print() override;
  double getPrice();

protected:
  Rose(Rose &toCopy);

private:
  double price;
};

#endif
