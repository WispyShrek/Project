#ifndef PLANT_H
#define PLANT_H
#include <string>
#include "Garden.h"
#include "PlantState.h"
#include "CareStrategy.h"
#include "PlantMemento.h"

class Plant : Garden {

private:
	PlantState* currState;
	CareStrategy* strategy;
	std::string colour;
	std::string scent;
	int length;

public:
	Plant();
	~Plant();
	std::string getState();
	void setState(PlantState* state);
	void nextState();
	void prevState();
	void applyCare();
	void Print();
	void addCust();
	PlantMemento* createPlantMemento();
	void setPlantMemento(PlantMemento* memento);
	virtual Plant* clone() = 0;

protected:
	Plant(Plant& toCopy);
};

#endif
