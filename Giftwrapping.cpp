#include "Giftwrapping.h"
#include <sstream>

/// @brief Increases the price of the plant by 100 units.
/// This method applies the cost of the giftwrapping decoration.
void Giftwrapping::increasePrice() {
  plant->increasePrice(100); // increase price by 100 for giftwrapping
}

/// @brief Associates a customer with the decorated plant.
/// Delegates the customer assignment to the underlying plant.
/// @param customer Pointer to the Customer object.
void Giftwrapping::addCust(Customer *customer) {
  plant->addCust(customer); // delegation
}

/// @brief Prints the details of the plant with giftwrapping decoration.
/// @return A string with the plant details and giftwrapping information.
std::string Giftwrapping::print() // prints giftwrapping details
{
  std::stringstream wrapping;
  wrapping << "Giftwrapping Details: " << std::endl;
  wrapping << plant->print();
  wrapping << "\nwith Giftwrapping decoration." << std::endl;
  return wrapping.str();
}
