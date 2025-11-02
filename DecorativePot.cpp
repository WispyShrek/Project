#include "DecorativePot.h"
#include <sstream>
// Default constructor and destructor can be omitted if not needed
void DecorativePot::increasePrice() {
  plant->increasePrice(200); // increase price by 200 for decorative pot
}

void DecorativePot::addCust(
    Customer *customer) // adds the customer to the plant's customer pointer
{
  plant->addCust(customer); // delegation
}
std::string DecorativePot::print() // prints decorative pot details
{
  std::stringstream pot;
  pot << "Decorative Pot Details: " << std::endl;
  pot << plant->print();
  pot << "\nwith Decorative Pot decoration." << std::endl;
  return pot.str();
}
