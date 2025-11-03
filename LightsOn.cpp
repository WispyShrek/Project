/**
 * @file LightsOn.cpp
 * @brief Implementation of the LightsOn command class.
 */
#include "LightsOn.h"

/**
 * @brief Constructor for the LightsOn command.
 *
 * Initializes the command and creates an instance of the `Light` object (the Receiver)
 * that this command will control.
 */
LightsOn::LightsOn() : lights(new Light) {} 

/**
 * @brief Executes the command to turn the lights on.
 *
 * This method calls the `turnOn` action on the associated `Light` object.
 */
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