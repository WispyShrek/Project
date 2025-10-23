#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
class Rose : public Plant {
public:
  Rose();
  Rose *clone();
  void print() override;

protected:
  Rose(Rose &toCopy);
};

#endif
