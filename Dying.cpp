#include "Dying.h"

/**
 * @brief Transitions the plant from the Dying state to the Dead state.
 *
 * This method changes the state of the `context` (the Plant) to a new `Dead` state.
 * @param context A pointer to the Plant object whose state is to be changed.
 */
void Dying::next(Plant* context) {
	context->setState(new Dead());
}

/**
 * @brief Creates a copy of the Dying state object.
 * @return A new `PlantState` pointer to a `Dying` object.
 */
PlantState* Dying::clone() const {
    return new Dying(*this);
}

/**
 * @brief Prints a message indicating the plant's current state is Dying.
 */
void Dying::print() {
	std::cout << "This plant is dying, apply care to it" << std::endl;
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"
// Forward declare MockPlant if it's in another file's test section
class MockPlant : public Plant {
public:
    MockPlant() : Plant() {}
    std::string getName() override { return "MockPlant"; }
    Plant* clone() override { return new MockPlant(*this); }
    void print() override {}
};

TEST_CASE("Dying State: Test Dying class methods") {
  Dying dyingState;
  Plant *mockPlant =
      nullptr; // Using nullptr as we won't modify the plant in this test

  // Test next method
  dyingState.next(mockPlant); // Currently does nothing

  // Test print method
  std::string sprite = "";
  dyingState.print(
      sprite); // Should print "This plant is dying, apply care to it"

  // Test clone method
  PlantState *clonedState = dyingState.clone();
  REQUIRE(clonedState != nullptr);
  delete clonedState;
}
#endif