#include "Giftwrapping.h"

/// @brief Increases the price of the plant by 100 units.
/// This method applies the cost of the giftwrapping decoration.
void Giftwrapping::increasePrice()
{
	plant->increasePrice(100); // increase price by 100 for giftwrapping
}

/// @brief Associates a customer with the decorated plant.
/// Delegates the customer assignment to the underlying plant.
/// @param customer Pointer to the Customer object.
void Giftwrapping::addCust(Customer *customer)
{
	plant->addCust(customer); // delegation
}

/// @brief Prints the details of the plant with giftwrapping decoration.
/// Outputs the base plant details followed by giftwrapping info.
void Giftwrapping::print()
{
	std::cout << "Giftwrapping Details: " << std::endl;
	plant->print();
	std::cout << "with Giftwrapping decoration." << std::endl;
}