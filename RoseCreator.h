#ifndef ROSECREATOR_H
#define ROSECREATOR_H

#include "PlantCreator.h"

class RoseCreator : public PlantCreator {
public:
  Plant *createPlant();
  RoseCreator();
};

#endif
