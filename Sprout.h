#ifndef SPROUT_H
#define SPROUT_H

#include "PlantState.h"
#include "Plant.h"

class Sprout : PlantState{
public:
	void next(Plant* context);
	void prev(Plant* context);
};

#endif
