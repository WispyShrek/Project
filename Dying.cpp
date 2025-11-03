#include "Dying.h"

Dying::Dying(Caretaker *prevStateCarer) {
  this->prevStateCarer = prevStateCarer;
  this->name = "Dying";
}
void Dying::next(Plant *context) { context->setState(new Dead()); }
void Dying::prev(Plant *context) {
  context->setState(prevStateCarer->getPlantMemento()->getState());
  delete prevStateCarer;
  prevStateCarer = nullptr;
}

PlantState *Dying::clone() const { return new Dying(*this); }

void Dying::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;178m^-\\");
}

// #ifdef ENABLE_DOCTESTS
// #include "doctest.h"

// TEST_CASE("Dying State: Test Dying class methods") {
//   Dying dyingState; // This uses the constructor that doesn't set prevStateCarer
//   // We need a valid plant object to call setState on.
//   Plant *mockPlant = new MockPlant();

//   // Test next method
//   dyingState.next(mockPlant); // This should now work
//   // Verify that the state was changed correctly
//   CHECK(mockPlant->getState() == "Dead");

//   // Test print method
//   std::string sprite = "";
//   dyingState.print(
//       sprite); // Should print "This plant is dying, apply care to it"

//   // Test clone method
//   PlantState *clonedState = dyingState.clone();
//   REQUIRE(clonedState != nullptr);
//   delete clonedState;
//   delete mockPlant; // Clean up the allocated mock plant
// }
// #endif
