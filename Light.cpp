/**
 * @file Light.cpp
 * @brief Implementation of the Light class.
 */
#include "Light.h"

#include <iostream>

/**
 * @brief Turns the light system on.
 *
 * This method simulates turning on the lights by printing "Light: ON" to the console.
 */
void Light::turnOn() {
	std::cout << "Light: ON" << std::endl;
}

/**
 * @brief Turns the light system off.
 *
 * This method simulates turning off the lights by printing "Light: OFF" to the console.
 */
void Light::turnOff() {
	std::cout << "Light: OFF" << std::endl;
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Light: Test Light class methods") {
	Light light;

	// Test turnOn method
	light.turnOn(); // Should print "Light: ON"

	// Test turnOff method
	light.turnOff(); // Should print "Light: OFF"
}
#endif