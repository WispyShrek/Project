#include "Sprout.h"

void Sprout::next(Plant *context) {
  if (!context)
    return;
  context->setState(new Flowering());
}

void Sprout::print(std::string &sprite) {
  sprite.clear();
  sprite.append("This is a sprout");
}

PlantState *Sprout::clone() const { return new Sprout(*this); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

// TEST_CASE("Sprout State: Test Sprout class methods") {
//   Sprout sproutState;
//   Plant *mockPlant = new MockPlant();
// 
//   // Test next method
//   sproutState.next(mockPlant);
//   CHECK(mockPlant->getState() == "Flowering");
// 
//   // Test print method
//   std::string sprite = "";
//   sproutState.print(sprite);
//   CHECK(sprite.find("sprout") != std::string::npos);
// 
//   // Test clone method
//   PlantState *clonedState = sproutState.clone();
//   REQUIRE(clonedState != nullptr);
//   delete clonedState;
//   delete mockPlant;
// }
#endif
