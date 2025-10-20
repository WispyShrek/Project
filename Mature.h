#ifndef MATURE_H
#define MATURE_H

#include "PlantState.h"
#include "Plant.h"

class Mature : PlantState{
public:
	void next(Plant* context);
	void prev(Plant* context);
};

#endif
