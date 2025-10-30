#include "LightsOff.h"

LightsOff::LightsOff() : lights(new Light) {}

void LightsOff::execute() {
	lights->turnOff();
}
 