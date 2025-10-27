#ifndef GREENHOUSECONTROLLER_H
#define GREENHOUSECONTROLLER_H
#include "Command.h"
#include "SprinklersOn.h"
#include "SprinklersOff.h"
 
class GreenhouseController{
private:
	Command* upCommand;
	Command* downCommand;

public:
	GreenhouseController();
	~GreenhouseController();
	void flipUp();
	void flipDown();
};

#endif
