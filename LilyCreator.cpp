#include "LilyCreator.h"
#include "Lily.h"

Plant* LilyCreator::createPlant() {
	return new Lily();
}

LilyCreator::LilyCreator() = default;



#ifdef ENABLE_DOCTESTS
#include "doctest.h"
TEST_CASE("LilyCreator: Test LilyCreator class") {
	LilyCreator creator;
	Plant* plant = creator.createPlant();

	REQUIRE(plant != nullptr);
	REQUIRE(plant->getName() == "Lily");

	delete plant;
}
#endif