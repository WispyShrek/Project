#include "Dead.h"
void Dead::next(Plant *context) {
    std::cout << "The plant is already dead and cannot transition to another state." << std::endl;
}
void Dead::print() {
    std::cout << "The plant is dead." << std::endl;
}
PlantState* Dead::clone() const {
    return new Dead(*this);
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Dead State: Test Dead class methods") {
    Dead deadState;
    Plant* mockPlant = nullptr; // Using nullptr as we won't modify the plant in this test

    // Test next method
    deadState.next(mockPlant); // Should print a message about being dead

    // Test print method
    deadState.print(); // Should print "The plant is dead."

    // Test clone method
    PlantState* clonedState = deadState.clone();
    REQUIRE(clonedState != nullptr);
    delete clonedState;
}
#endif