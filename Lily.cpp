/**
 * @file Lily.cpp
 * @brief Implementation of the Lily class.
 */
#include "Lily.h"

/**
 * @brief Default constructor for the Lily class.
 * Initializes a Lily plant with a default care strategy of PartialSunCare and a price of 70.
 */
Lily::Lily() {
  this->strategy = new PartialSunCare();
  this->price = 70;
};

/**
 * @brief Gets the name of the plant.
 * @return The string "Lily".
 */
std::string Lily::getName() {
	return "Lily";
}

/**
 * @brief Creates a deep copy of the Lily object.
 * @return A new `Lily` pointer that is a clone of the current instance.
 */
Lily* Lily::clone() {
	return new Lily(*this);
}

/**
 * @brief Prints the name of the plant to the console.
 */
void Lily::print(){
	std::cout << "Lily" << std::endl;
}

/**
 * @brief Gets the price of the Lily plant.
 * @return The price of the plant as a double.
 */
double Lily::getPrice() {
	return price;
}

/**
 * @brief Copy constructor for the Lily class.
 *
 * Creates a new Lily object by copying the state of an existing one,
 * including its base Plant attributes and its specific price.
 * @param toCopy A reference to the Lily object to be copied.
 */
Lily::Lily(Lily& toCopy)  : Plant(toCopy) {
	this->price = toCopy.price;
}

double Lily::getPrice() { return price; }

Lily::Lily(Lily &toCopy) : Plant(toCopy) { this->price = toCopy.price; }

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Lily: Test Lily class methods") {
  Lily lily;

  // Test getName method
  REQUIRE(lily.getName() == "Lily");

  // Test getPrice method
  REQUIRE(lily.getPrice() == 70);

  // Test clone method
  Lily *clonedLily = lily.clone();
  REQUIRE(clonedLily != nullptr);
  REQUIRE(clonedLily->getName() == "Lily");
  REQUIRE(clonedLily->getPrice() == 70);
  delete clonedLily;

  // Test print method (just ensure it runs without error)
  lily.print();
}
#endif
