#include "Light.h"

#include <iostream>

void Light::turnOn() {
	std::cout << "Light: ON" << std::endl;
}

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