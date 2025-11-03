#include "Rose.h"

Rose::Rose() {
  this->strategy = new SunnyCare();
  this->price = 80;
};

std::string Rose::getName() { return "Rose"; }

Rose *Rose::clone() { return new Rose(*this); }

std::string Rose::print() {
  std::string sprite;
  sprite.append("\x1B[38;5;196m@>");

  this->currState->print(sprite);
  return sprite;
}

double Rose::getPrice() { return price; }

Rose::Rose(Rose &toCopy) : Plant(toCopy) { this->price = toCopy.price; }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Rose: Test Rose class methods") {
  Rose rose;

  // Test getName method
  REQUIRE(rose.getName() == "Rose");

  // Test getPrice method
  REQUIRE(rose.getPrice() == 80);

  // Test clone method
  Rose *clonedRose = rose.clone();
  REQUIRE(clonedRose != nullptr);
  REQUIRE(clonedRose->getName() == "Rose");
  REQUIRE(clonedRose->getPrice() == 80);
  delete clonedRose;

  // Test print method (just ensure it runs without error)
  rose.print();
}
#endif
