#ifndef LILY_H
#define LILY_H

#include "Plant.h"

class Lily : public Plant {
public:
  Lily();
  std::string getName();
  Lily *clone();
  void print() override;

protected:
  Lily(Lily &toCopy);
};

#endif
