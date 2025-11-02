#include "Arrangement.h"
#include <sstream>
// Default constructor and destructor can be omitted if not needed
Arrangement::~Arrangement() {}    // destructor
void Arrangement::increasePrice() // increases price by 150 for arrangement
{
  plant->increasePrice(150);
}

void Arrangement::addCust(
    Customer *customer) // adds the customer to the plant's customer pointer
{
  plant->addCust(customer); // delegation
}
std::string Arrangement::print() // prints arrangement details
{
  std::stringstream arrangement;
  arrangement << "Arrangement Details: " << std::endl;
  arrangement << plant->print();
  arrangement << "\nwith Arrangement decoration." << std::endl;
  return arrangement.str();
}
