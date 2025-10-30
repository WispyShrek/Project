#ifndef TULIPCREATOR_H
#define TULIPCREATOR_H

#include "PlantCreator.h"

class TulipCreator : public PlantCreator {
public:
  Plant *createPlant();
  TulipCreator();
};

#endif
