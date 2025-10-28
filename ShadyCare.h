#ifndef SHADYCARE_H
#define SHADYCARE_H
#include <iostream>

#include "CareStrategy.h"

class ShadyCare : public CareStrategy {
public:
  ShadyCare();
  void applyCare();
  void applyCare() override;
};

#endif
