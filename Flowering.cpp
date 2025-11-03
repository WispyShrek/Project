/**
 * @file Flowering.cpp
 * @brief Implementation of the Flowering class, a concrete state in the State pattern.
 */
#include "Flowering.h"

/**
 * @brief Transitions the plant from the Flowering state to the Mature state.
 *
 * This method changes the state of the `context` (the Plant) to a new `Mature` state.
 * It performs a null check on the context before proceeding.
 * @param context A pointer to the Plant object whose state is to be changed.
 */
void Flowering::next(Plant* context) {
    if (!context) return;
    context->setState(new Mature());
	return;
}

/**
 * @brief Creates a copy of the Flowering state object.
 * @return A new `PlantState` pointer to a `Flowering` object.
 */
PlantState* Flowering::clone() const {
    return new Flowering(*this);
}

/**
 * @brief Prints a message indicating the plant's current state is Flowering.
 */
void Flowering::print() {
	std::cout << "This is a plant that is flowering" << std::endl;
}

void Flowering::print(std::string &sprite) { sprite.append("\x1B[38;5;28m->"); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Flowering State: Test Flowering class methods") {
  Flowering floweringState;
  Plant *mockPlant =
      nullptr; // Using nullptr as we won't modify the plant in this test

  // Test next method
  floweringState.next(
      mockPlant); // Currently does nothing since mockPlant is nullptr

  // Test print method
  std::string sprite = "";
  floweringState.print(
      sprite); // Should print "This is a plant that is flowering"

  // Test clone method
  PlantState *clonedState = floweringState.clone();
  REQUIRE(clonedState != nullptr);
  delete clonedState;
}
#endif
