#include "Flowering.h"

void Flowering::next(Plant *context) {
  if (!context)
    return;
  context->setState(new Mature());
  return;
}

PlantState *Flowering::clone() const { return new Flowering(*this); }

void Flowering::print(std::string &sprite) { sprite.append("\x1B[38;5;28m->"); }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

// TEST_CASE("Flowering State: Test Flowering class methods") {
//   Flowering floweringState;
//   Plant *mockPlant = new MockPlant();
// 
//   // Test next method
//   floweringState.next(mockPlant);
//   CHECK(mockPlant->getState() == "Mature");
// 
//   // Test print method
//   std::string sprite = "";
//   floweringState.print(sprite);
//   CHECK(sprite.find("->") != std::string::npos);
// 
//   // Test clone method
//   PlantState *clonedState = floweringState.clone();
//   REQUIRE(clonedState != nullptr);
//   delete clonedState;
//   delete mockPlant;
// }
#endif
