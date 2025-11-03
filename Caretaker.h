#ifndef CARETAKER_H
#define CARETAKER_H
#include "PlantMemento.h"

class Caretaker{
private:
	PlantMemento* memento;
public:
	virtual ~Caretaker();
	PlantMemento* getPlantMemento();
	void setPlantMemento(PlantMemento* memento);
};

#endif
