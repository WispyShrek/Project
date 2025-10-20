#ifndef LIGHTSOFF_H
#define LIGHTSOFF_H

#include "Command.h"
#include "Light.h"

class LightsOff : Command{
public:
	Light* lights;
	LightsOff();
	void execute();
};

#endif
