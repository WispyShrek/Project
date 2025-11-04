#include "Sprinkler.h"

#include <iostream>

Sprinkler::Sprinkler(greenHouse *greenhouse) { this->greenhouse = greenhouse; }

void Sprinkler::turnOn() { std::cout << "Sprinkler: ON" << std::endl; }

void Sprinkler::turnOff() { std::cout << "Sprinkler: OFF" << std::endl; }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Sprinkler: Test Sprinkler class methods") {
  Sprinkler sprinkler;

  // Test turnOn method
  sprinkler.turnOn(); // Should print "Sprinkler: ON"

  // Test turnOff method
  sprinkler.turnOff(); // Should print "Sprinkler: OFF"
}
#endif
