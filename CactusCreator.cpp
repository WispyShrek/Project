#include "CactusCreator.h"
#include "Cactus.h"

Plant *CactusCreator::createPlant(){
    return new Cactus();
}

CactusCreator::CactusCreator() = default;

#ifdef ENABLE_DOCTESTS
#include "doctest.h"
TEST_CASE("CactusCreator: Test CactusCreator class") {
	CactusCreator creator;
	Plant* plant = creator.createPlant();

	REQUIRE(plant != nullptr);
	REQUIRE(plant->getName() == "Cactus");

	delete plant;
}
#endif
