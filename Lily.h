#ifndef LILY_H
#define LILY_H

#include "Plant.h"

class Lily : public Plant {
public:
  Lily();
  Lily *clone();
  void print() override;

protected:
  Lily(Lily &toCopy);
};

#endif
