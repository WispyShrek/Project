#include "Arrangement.h"
// Default constructor and destructor can be omitted if not needed
Arrangement::~Arrangement(){} // destructor
void Arrangement::increasePrice()//increases price by 150 for arrangement
{
	plant->increasePrice(150);
}

void Arrangement::addCust(Customer *customer)//adds the customer to the plant's customer pointer
{
	plant->addCust(customer);//delegation
}
void Arrangement::print()//prints arrangement details
{
	std::cout << "Arrangement Details: " << std::endl;
	plant->print();
	std::cout << "with Arrangement decoration." << std::endl;
}

