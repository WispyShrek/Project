#ifndef SUNNYCARE_H
#define SUNNYCARE_H
#include <iostream>

#include "CareStrategy.h"

class SunnyCare : public CareStrategy {
public:
  void applyCare() override;
};

#endif
