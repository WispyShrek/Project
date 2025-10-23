#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"

class Lavender : public Plant {

public:
  Lavender();

  Lavender *clone();

protected:
  Lavender(Lavender &toCopy);
};

#endif
