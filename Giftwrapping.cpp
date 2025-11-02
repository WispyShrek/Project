#include "Giftwrapping.h"

// Default constructor and destructor can be omitted if not needed
void Giftwrapping::increasePrice()
{
	plant->increasePrice(100);//increase price by 100 for giftwrapping
}

void Giftwrapping::addCust(Customer *customer)//adds the customer to the plant's customer pointer
{
	plant->addCust(customer);//delegation
}
void Giftwrapping::print()//prints giftwrapping details
{
	std::cout << "Giftwrapping Details: " << std::endl;
	plant->print();
	std::cout << "with Giftwrapping decoration." << std::endl;
}
