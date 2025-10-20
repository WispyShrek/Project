#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H
#include "PlantCreator.h"
#include "Plant.h"

class LavenderCreator : PlantCreator{
public:
	Plant* createPlant();
	LavenderCreator();
};

#endif
