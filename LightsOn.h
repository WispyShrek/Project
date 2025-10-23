#ifndef LIGHTSON_H
#define LIGHTSON_H

#include "Command.h"
#include "Light.h"

class LightsOn : public Command {

public:
  Light *lights;
  LightsOn();
  void execute();
};

#endif
