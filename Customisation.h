#ifndef CUSTOMISATION_H
#define CUSTOMISATION_H
#include "Plant.h"

class Customisation : Plant{

public:
	Plant* plant;
	virtual void increasePrice() = 0;
	virtual void addCust() = 0;
};

#endif
