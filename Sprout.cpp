#include "Sprout.h"

void Sprout::next(Plant* context) {
    if (!context) return;
    context->setState(new Flowering());
}

void Sprout::print() {
	std::cout << "This is a sprout" << std::endl;
	// TODO - implement Sprout::next
	return;
}

PlantState* Sprout::clone() const {
    return new Sprout(*this);
}



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Sprout State: Test Sprout class methods") {
    Sprout sproutState;
    Plant* mockPlant = nullptr; // Using nullptr as we won't modify the plant in this test

    // Test next method
    sproutState.next(mockPlant); // Currently does nothing since mockPlant is nullptr

    // Test print method
    sproutState.print(); // Should print "This is a sprout"

    // Test clone method
    PlantState* clonedState = sproutState.clone();
    REQUIRE(clonedState != nullptr);
    delete clonedState;
}
#endif