#include "LightsOn.h"

LightsOn::LightsOn() : lights(new Light) {} 

void LightsOn::execute() {
	lights->turnOn();
}



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("LightsOn: Test LightsOn class methods") {
	LightsOn lightsOnCommand;

	// Test execute method
	lightsOnCommand.execute(); // Should turn on the lights (prints "Light: ON")
}
#endif