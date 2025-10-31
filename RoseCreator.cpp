#include "RoseCreator.h"
#include "Rose.h"

Plant* RoseCreator::createPlant() {
	return new Rose();
}

RoseCreator::RoseCreator() = default;


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("RoseCreator: Test RoseCreator class") {
	RoseCreator creator;
	Plant* plant = creator.createPlant();

	REQUIRE(plant != nullptr);
	REQUIRE(plant->getName() == "Rose");

	delete plant;
}
#endif