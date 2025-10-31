#include "Dying.h"

void Dying::next(Plant* context) {
	// TODO - implement Dying::next
	return;
}

PlantState* Dying::clone() const {
    return new Dying(*this);
}

void Dying::print() {
	std::cout << "This plant is dying, apply care to it" << std::endl;
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Dying State: Test Dying class methods") {
	Dying dyingState;
	Plant* mockPlant = nullptr; // Using nullptr as we won't modify the plant in this test

	// Test next method
	dyingState.next(mockPlant); // Currently does nothing

	// Test print method
	dyingState.print(); // Should print "This plant is dying, apply care to it"

	// Test clone method
	PlantState* clonedState = dyingState.clone();
	REQUIRE(clonedState != nullptr);
	delete clonedState;
}
#endif