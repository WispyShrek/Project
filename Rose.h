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

protected:
  Rose(Rose &toCopy);
};

#endif
