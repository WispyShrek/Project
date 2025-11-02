#include "PlantCreator.h"

PlantCreator::PlantCreator(): plant(nullptr) {}

PlantCreator::~PlantCreator() = default;



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("PlantCreator: Test PlantCreator class") {
    class MockPlantCreator : public PlantCreator {
    protected:
        Plant* createPlant() override {
            return nullptr; // Just for testing
        }
    };

    MockPlantCreator creator;
    // Since createPlant is protected, we cannot call it directly here.
    // This test just ensures that the constructor and destructor work without error.
}
#endif