#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "Garden.h"
#include <vector>

class greenHouse{
private:
	std::vector<Garden*> gardens;
public:
	void powerSystem();
};

#endif
