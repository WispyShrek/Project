#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
class Rose : Plant{
public:
	Rose();
	Rose* clone();

protected:
	Rose(Rose& toCopy);
};

#endif
