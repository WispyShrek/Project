#ifndef TULIP_H
#define TULIP_H

#include "Plant.h"

class Tulip : public Plant {
public:
  Tulip();
  Tulip *clone();
  void print() override;

protected:
  Tulip(Tulip &toCopy);
};

#endif
