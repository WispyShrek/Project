#include "DecorativePot.h"
#include <sstream>

/// @brief Increases the price of the plant by 200 units.
/// This method applies the cost of the decorative pot decoration.
void DecorativePot::increasePrice() {
  plant->increasePrice(200); // increase price by 200 for decorative pot
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
