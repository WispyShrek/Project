#ifndef LILYCREATOR_H
#define LILYCREATOR_H

#include "PlantCreator.h"
#include "Plant.h"

class LilyCreator : PlantCreator{
public:
	Plant* createPlant();
	LilyCreator();
};

#endif
