#include "Giftwrapping.h"
#include <sstream>

// Default constructor and destructor can be omitted if not needed
void Giftwrapping::increasePrice() {
  plant->increasePrice(100); // increase price by 100 for giftwrapping
}

void Giftwrapping::addCust(
    Customer *customer) // adds the customer to the plant's customer pointer
{
  plant->addCust(customer); // delegation
}
std::string Giftwrapping::print() // prints giftwrapping details
{
  std::stringstream wrapping;
  wrapping << "Giftwrapping Details: " << std::endl;
  wrapping << plant->print();
  wrapping << "\nwith Giftwrapping decoration." << std::endl;
  return wrapping.str();
}
