#ifndef LIGHTSOFF_H
#define LIGHTSOFF_H

#include "Command.h"
#include "Light.h"

class LightsOff : public Command {
public:
  Light *lights;
  LightsOff();
  void execute();
};

#endif
 