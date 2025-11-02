#include "LavenderCreator.h"
#include "Lavender.h"

Plant* LavenderCreator::createPlant() {
	return new Lavender();
}

LavenderCreator::LavenderCreator() = default; 




#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("LavenderCreator: Test LavenderCreator class") {
	LavenderCreator creator;
	Plant* plant = creator.createPlant();

	REQUIRE(plant != nullptr);
	REQUIRE(plant->getName() == "Lavender");

	delete plant;
}
#endif
