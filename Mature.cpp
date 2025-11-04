#include "Mature.h"

void Mature::next(Plant *context) {
  if (!context)
    return;
}

void Mature::print(std::string &sprite) { sprite.append("\x1B[38;5;28m,->>"); }
PlantState *Mature::clone() const { return new Mature(*this); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

// TEST_CASE("Mature State: Test Mature class methods") {
//   Mature matureState;
//   Plant *mockPlant = new MockPlant();
//   mockPlant->setState(new Mature()); // Set initial state
// 
//   // Test next method
//   matureState.next(mockPlant); // next() is a no-op for Mature
//   CHECK(mockPlant->getState() == "Mature");
// 
//   // Test print method
//   std::string sprite = "";
//   matureState.print(sprite);
//   CHECK(sprite.find(",->>") != std::string::npos);
// 
//   // Test clone method
//   PlantState *clonedState = matureState.clone();
//   REQUIRE(clonedState != nullptr);
//   delete clonedState;
//   delete mockPlant;
// }
#endif
