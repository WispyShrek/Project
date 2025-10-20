#ifndef FLOWERING_H
#define FLOWERING_H
#include "PlantState.h"
#include "Plant.h"

class Flowering : PlantState{
public:
	void next(Plant* context);
	void prev(Plant* context);
};

#endif
