#include "TulipCreator.h"
#include "Tulip.h"

Plant* TulipCreator::createPlant() {
	return new Tulip();
}

TulipCreator::TulipCreator() = default;



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("TulipCreator: Test TulipCreator class") {
	TulipCreator creator;
	Plant* plant = creator.createPlant();

	REQUIRE(plant != nullptr);
	REQUIRE(plant->getName() == "Tulip");

	delete plant;
}
#endif