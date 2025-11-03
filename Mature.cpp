#include "Mature.h"

void Mature::next(Plant *context) {
  if (!context)
    return;
  std::cout << "Cannot grow more — already Mature.\n";
}



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Mature State: Test Mature class methods") {
    Mature matureState;
    Plant* mockPlant = nullptr; // Using nullptr as we won't modify the plant in this test

    // Test next method
    matureState.next(mockPlant); // Should print a message about being mature

    // Test print method
    matureState.print(); // Should print "This is a plant that is now Mature"

    // Test clone method
    PlantState* clonedState = matureState.clone();
    REQUIRE(clonedState != nullptr);
    delete clonedState;
}
#endif