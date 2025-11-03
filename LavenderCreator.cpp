/**
 * @file LavenderCreator.cpp
 * @brief Implementation of the LavenderCreator class.
 */
#include "LavenderCreator.h"
#include "Lavender.h"

/**
 * @brief Factory method to create a Lavender plant object.
 *
 * This method implements the factory pattern to instantiate and return a new
 * `Lavender` object, fulfilling the contract of the `PlantCreator` base class.
 * @return A pointer to a new Plant object, specifically a `Lavender`.
 */
Plant* LavenderCreator::createPlant() {
	return new Lavender();
}

/**
 * @brief Default constructor for the LavenderCreator.
 */
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
