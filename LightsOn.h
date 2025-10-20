#ifndef LIGHTSON_H
#define LIGHTSON_H

#include "Command.h"
#include "Light.h"

class LightsOn : Command{

public:
	Light* lights;
	LightsOn();
	void execute();
};

#endif
