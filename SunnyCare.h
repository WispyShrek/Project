#ifndef SUNNYCARE_H
#define SUNNYCARE_H
#include <iostream>

#include "CareStrategy.h"

class SunnyCare : public CareStrategy {
public:
  SunnyCare();
  void applyCare();
  void applyCare() override;
};

#endif
