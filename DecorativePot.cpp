/**
 * @file DecorativePot.cpp
 * @brief Implementation of the DecorativePot concrete decorator.
 */
#include "DecorativePot.h"
#include <sstream>

/**
 * @brief Increases the price of the wrapped plant by a fixed amount for the decorative pot.
 *
 * This method is an implementation of the decorator functionality. It calls the
 * `increasePrice` method on the wrapped `Plant` object, adding the cost
 * specific to this decorative pot (200).
 */
void DecorativePot::increasePrice()
{
	plant->increasePrice(200);
}
/// @brief Associates a customer with the decorated plant.
/// Delegates the customer assignment to the underlying plant.
/// @param customer Pointer to the Customer object.
void DecorativePot::addCust(Customer *customer) {
  plant->addCust(customer); // delegation
}
/// @brief Prints the details of the plant with decorative pot decoration.
/// Outputs the base plant details followed by decorative pot info.

std::string DecorativePot::print() {
  std::stringstream pot;
  pot << "Decorative Pot Details: " << std::endl;
  pot << plant->print();
  pot << "\nwith Decorative Pot decoration." << std::endl;
  return pot.str();
}
