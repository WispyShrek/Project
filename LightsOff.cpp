#include "LightsOff.h"

LightsOff::LightsOff() : lights(new Light) {}

void LightsOff::execute() {
	lights->turnOff();
}
 


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("LightsOff: Test LightsOff class methods") {
	LightsOff lightsOffCommand;

	// Test execute method
	lightsOffCommand.execute(); // Should turn off the lights (prints "Light: OFF")
}
#endif