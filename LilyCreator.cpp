/**
 * @file LilyCreator.cpp
 * @brief Implementation of the LilyCreator class.
 */
#include "LilyCreator.h"
#include "Lily.h"

/**
 * @brief Factory method to create a Lily plant object.
 *
 * This method implements the factory pattern to instantiate and return a new
 * `Lily` object, fulfilling the contract of the `PlantCreator` base class.
 * @return A pointer to a new Plant object, specifically a `Lily`.
 */
Plant* LilyCreator::createPlant() {
	return new Lily();
}

/**
 * @brief Default constructor for the LilyCreator.
 */
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