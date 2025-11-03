/**
 * @file Dying.cpp
 * @brief Implementation of the Dying class, a concrete state in the State pattern.
 */
#include "Dying.h"

Dying::Dying(Caretaker *prevStateCarer) {
  this->prevStateCarer = prevStateCarer;
  this->name = "Dying";
}
void Dying::next(Plant *context) { context->setState(new Dead()); }
void Dying::prev(Plant *context) {
  context->setState(prevStateCarer->getPlantMemento()->getState());
  delete prevStateCarer;
  prevStateCarer = nullptr;
}

PlantState *Dying::clone() const { return new Dying(*this); }

void Dying::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;178m^-\\");
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"
// Forward declare MockPlant if it's in another file's test section
class MockPlant : public Plant {
public:
    MockPlant() : Plant() {}
    std::string getName() override { return "MockPlant"; }
    Plant* clone() override { return new MockPlant(*this); }
};

TEST_CASE("Dying State: Test Dying class methods") {
	Dying dyingState;
	MockPlant mockPlant;
	REQUIRE(mockPlant.getState() == "Sprout");

	// Test next method
	dyingState.next(&mockPlant); // Pass a valid object
	CHECK(mockPlant.getState() == "Dead");

	// Test print method
	dyingState.print(); // Should print "This plant is dying, apply care to it"

	// Test clone method
	PlantState* clonedState = dyingState.clone();
	REQUIRE(clonedState != nullptr);
	delete clonedState;
}
#endif
