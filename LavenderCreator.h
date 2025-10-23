#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H
#include "Plant.h"
#include "PlantCreator.h"

class LavenderCreator : public PlantCreator {
public:
  Plant *createPlant();
  LavenderCreator();
};

#endif
