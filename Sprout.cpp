#include "Sprout.h"

void Sprout::next(Plant *context) {
  if (!context)
    return;
  context->setState(new Flowering());
}

void Sprout::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;40m->");
}

PlantState *Sprout::clone() const { return new Sprout(*this); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Sprout State: Test Sprout class methods") {
  Sprout sproutState;
  Plant *mockPlant =
      nullptr; // Using nullptr as we won't modify the plant in this test

  // Test next method
  sproutState.next(
      mockPlant); // Currently does nothing since mockPlant is nullptr

  // Test print method
  std::string sprite = "";
  sproutState.print(sprite); // Should print "This is a sprout"

  // Test clone method
  PlantState *clonedState = sproutState.clone();
  REQUIRE(clonedState != nullptr);
  delete clonedState;
}
#endif
