#include "Mature.h"

void Mature::next(Plant *context) {
  if (!context)
    return;
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
