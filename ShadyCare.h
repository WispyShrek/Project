#ifndef SHADYCARE_H
#define SHADYCARE_H

#include "CareStrategy.h"

class ShadyCare : public CareStrategy {
public:
  ShadyCare();
  void applyCare();
};

#endif
