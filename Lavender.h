#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"

class Lavender : Plant {


public:
	Lavender();

	Lavender* clone();

protected:
	Lavender(Lavender& toCopy);
};

#endif
