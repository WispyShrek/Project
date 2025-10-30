#ifndef LILYCREATOR_H
#define LILYCREATOR_H

#include "Plant.h"
#include "PlantCreator.h"

class LilyCreator : public PlantCreator {
public:
  Plant *createPlant();
  LilyCreator();
};

#endif
