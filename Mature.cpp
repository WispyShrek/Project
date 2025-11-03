/**
 * @file Mature.cpp
 * @brief Implementation of the Mature class, a concrete state in the State pattern.
 */
#include "Mature.h"

/**
 * @brief Handles state transitions from the Mature state.
 *
 * A plant in the Mature state is considered to have reached its final growth stage.
 * This method prints a message to indicate this and does not change the plant's context.
 * @param context A pointer to the Plant object (unused in this implementation).
 */
void Mature::next(Plant* context) {
    if (!context) return;
    std::cout << "Cannot grow more — already Mature.\n";
}

/**
 * @brief Prints a message indicating the plant's current state is Mature.
 */
void Mature::print() {	
	std::cout << "This is a plant that is now Mature" << std::endl;
}

/**
 * @brief Creates a copy of the Mature state object.
 * @return A new `PlantState` pointer to a `Mature` object.
 */
PlantState* Mature::clone() const {
    return new Mature(*this);
}

void Mature::print(std::string &sprite) { sprite.append("\x1B[38;5;28m,->>"); }
PlantState *Mature::clone() const { return new Mature(*this); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Mature State: Test Mature class methods") {
  Mature matureState;
  Plant *mockPlant =
      nullptr; // Using nullptr as we won't modify the plant in this test

  // Test next method
  matureState.next(mockPlant); // Should print a message about being mature

  // Test print method
  std::string sprite = "";
  matureState.print(
      sprite); // Should print "This is a plant that is now Mature"

  // Test clone method
  PlantState *clonedState = matureState.clone();
  REQUIRE(clonedState != nullptr);
  delete clonedState;
}
#endif
