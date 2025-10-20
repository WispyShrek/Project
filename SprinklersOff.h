#ifndef SPRINKLERSOFF_H
#define SPRINKLERSOFF_H

#include "Command.h"
#include "Sprinkler.h"

class SprinklersOff : Command {

public:
	Sprinkler* sprinklers;

	SprinklersOff();

	void execute();
};

#endif
