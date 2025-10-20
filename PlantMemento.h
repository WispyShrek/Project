#ifndef PLANTMEMENTO_H
#define PLANTMEMENTO_H

#include "PlantState.h"

class PlantMemento{
private:
	PlantState* currState;
public:
	PlantState* getState();
	void setState(PlantState* state);
};

#endif
