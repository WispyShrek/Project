#include "Lily.h"

Lily::Lily() {
	this->strategy = new PartialSunCare();
	this->price = 70;
};

std::string Lily::getName() { return "Lily"; }

Lily *Lily::clone() { return new Lily(*this); }

std::string Lily::print() {
  std::string sprite;
  sprite.append("\x1B[38;5;226m o");

  sprite.append("\x1B[38;5;231m}");
  this->currState->print(sprite);
  return sprite;
}



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Lily: Test Lily class methods") {
	Lily lily;

	// Test getName method
	REQUIRE(lily.getName() == "Lily");

	// Test getPrice method
	REQUIRE(lily.getPrice() == 70);

	// Test clone method
	Lily* clonedLily = lily.clone();
	REQUIRE(clonedLily != nullptr);
	REQUIRE(clonedLily->getName() == "Lily");
	REQUIRE(clonedLily->getPrice() == 70);
	delete clonedLily;

	// Test print method (just ensure it runs without error)
	lily.print();
}
#endif
