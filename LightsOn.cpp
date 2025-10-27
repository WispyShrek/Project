#include "LightsOn.h"

LightsOn::LightsOn() : lights(new Light) {} 

void LightsOn::execute() {
	lights->turnOn();
}
