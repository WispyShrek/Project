#ifndef SHADYCARE_H
#define SHADYCARE_H
#include <iostream>

#include "CareStrategy.h"

class ShadyCare : public CareStrategy {
public:
  void applyCare() override;
};

#endif
