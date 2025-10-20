#ifndef DYING_H
#define DYING_H
#include "PlantState.h"
#include "Plant.h"

class Dying : PlantState{
public:
	void next(Plant* context);
	void prev(Plant* context);
};

#endif
