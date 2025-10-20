#ifndef SPRINKLERSON_H
#define SPRINKLERSON_H

#include "Command.h"
#include "Sprinkler.h"

class SprinklersOn : Command {
public:
	Sprinkler* sprinklers;
	SprinklersOn();
	void execute();
};

#endif
