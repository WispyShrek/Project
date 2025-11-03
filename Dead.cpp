/**
 * @file Dead.cpp
 * @brief Implementation of the Dead class, a concrete state in the State pattern.
 */
#include "Dead.h"
void Dead::next(Plant *context) {}
void Dead::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;242m-\\");
}
PlantState *Dead::clone() const { return new Dead(*this); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Dead State: Test Dead class methods") {
  Dead deadState;
  Plant *mockPlant =
      nullptr; // Using nullptr as we won't modify the plant in this test

  // Test next method
  deadState.next(mockPlant); // Should print a message about being dead

  // Test print method
  std::string sprite = "";
  deadState.print(sprite); // Should print "The plant is dead."

  // Test clone method
  PlantState *clonedState = deadState.clone();
  REQUIRE(clonedState != nullptr);
  delete clonedState;
}
#endif
