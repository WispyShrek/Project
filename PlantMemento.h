#ifndef PLANTMEMENTO_H
#define PLANTMEMENTO_H

#include "PlantState.h"

class PlantMemento{
private:
	PlantState* currState;
public:
    PlantMemento();
    PlantMemento(PlantState* state);
    ~PlantMemento();

    PlantState* getState() const;
    void setState(PlantState* state);
};

#endif
