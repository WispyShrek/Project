#ifndef TULIP_H
#define TULIP_H

#include "Plant.h"

class Tulip : Plant {
public:
	Tulip();
	Tulip* clone();

protected:
	Tulip(Tulip& toCopy);
};

#endif
