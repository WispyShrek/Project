#ifndef GREENHOUSECONTROLLER_H
#define GREENHOUSECONTROLLER_H
#include "Command.h"
 
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
