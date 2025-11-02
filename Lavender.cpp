/**
 * @file Lavender.cpp
 * @brief Implementation of the Lavender class.
 */
#include "Lavender.h"

/**
 * @brief Default constructor for the Lavender class.
 * Initializes a Lavender plant with a default care strategy of PartialSunCare and a price of 60.
 */
Lavender::Lavender() {
	this->strategy = new PartialSunCare();
	this->price = 60;
};

/**
 * @brief Gets the name of the plant.
 * @return The string "Lavender".
 */
std::string Lavender::getName() {
	return "Lavender";
}

/**
 * @brief Creates a deep copy of the Lavender object.
 * @return A new `Lavender` pointer that is a clone of the current instance.
 */
Lavender* Lavender::clone() {
	return new Lavender(*this);
}

/**
 * @brief Prints the name of the plant to the console.
 */
void Lavender::print(){
	std::cout << "Lavender" << std::endl;
}

/**
 * @brief Gets the price of the Lavender plant.
 * @return The price of the plant as a double.
 */
double Lavender::getPrice() {
	return price;
}

/**
 * @brief Copy constructor for the Lavender class.
 *
 * Creates a new Lavender object by copying the state of an existing one,
 * including its base Plant attributes and its specific price.
 * @param toCopy A reference to the Lavender object to be copied.
 */
Lavender::Lavender(Lavender& toCopy) : Plant(toCopy) {
	this->price = toCopy.price;
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Lavender: Test Lavender class methods") {
	Lavender lavender;

	// Test getName method
	REQUIRE(lavender.getName() == "Lavender");

	// Test getPrice method
	REQUIRE(lavender.getPrice() == 60);

	// Test clone method
	Lavender* clonedLavender = lavender.clone();
	REQUIRE(clonedLavender != nullptr);
	REQUIRE(clonedLavender->getName() == "Lavender");
	REQUIRE(clonedLavender->getPrice() == 60);
	delete clonedLavender;

	// Test print method (just ensure it runs without error)
	lavender.print();
}
#endif
