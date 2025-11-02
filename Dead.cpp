/**
 * @file Dead.cpp
 * @brief Implementation of the Dead class, a concrete state in the State pattern.
 */
#include "Dead.h"

/**
 * @brief Handles state transitions from the Dead state.
 *
 * A plant in the Dead state cannot transition to any other state. This method
 * prints a message to indicate this and does not change the plant's context.
 * @param context A pointer to the Plant object (unused in this implementation).
 */
void Dead::next(Plant *context) {
    std::cout << "The plant is already dead and cannot transition to another state." << std::endl;
}

/**
 * @brief Prints a message indicating the plant's current state is Dead.
 */
void Dead::print() {
    std::cout << "The plant is dead." << std::endl;
}

/**
 * @brief Creates a copy of the Dead state object.
 * @return A new `PlantState` pointer to a `Dead` object.
 */
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
