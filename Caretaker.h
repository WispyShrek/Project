#ifndef CARETAKER_H
#define CARETAKER_H
#include "PlantMemento.h"

class Caretaker{
private:
	PlantMemento* memento;
public:
	PlantMemento* getPlantMemento();
	void setPlantMemento(PlantMemento* memento);
};

#endif
