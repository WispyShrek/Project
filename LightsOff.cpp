/**
 * @file LightsOff.cpp
 * @brief Implementation of the LightsOff command class.
 */
#include "LightsOff.h"

/**
 * @brief Constructor for the LightsOff command.
 *
 * Initializes the command and creates an instance of the `Light` object (the Receiver)
 * that this command will control.
 */
LightsOff::LightsOff() : lights(new Light) {}

/**
 * @brief Executes the command to turn the lights off.
 *
 * This method calls the `turnOff` action on the associated `Light` object.
 */
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