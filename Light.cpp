#include "Light.h"

#include <iostream>

Light::Light(greenHouse *greenHouse) { this->greenhouse = greenHouse; }

void Light::turnOn() { greenhouse->bright = true; }

void Light::turnOff() { greenhouse->bright = false; }

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
