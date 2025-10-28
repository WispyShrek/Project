#ifndef PARTIALSUNCARE_H
#define PARTIALSUNCARE_H
#include <iostream>

#include "CareStrategy.h"

class PartialSunCare : public CareStrategy {
public:
  PartialSunCare();
  void applyCare();
  void applyCare() override;
};

#endif
