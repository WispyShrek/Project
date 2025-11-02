#include "DecorativePot.h"
// Default constructor and destructor can be omitted if not needed
void DecorativePot::increasePrice()
{
	plant->increasePrice(200);//increase price by 200 for decorative pot
}

void DecorativePot::addCust(Customer *customer)//adds the customer to the plant's customer pointer
{
	plant->addCust(customer);//delegation
}
void DecorativePot::print()//prints decorative pot details
{
	std::cout << "Decorative Pot Details: " << std::endl;
	plant->print();
	std::cout << "with Decorative Pot decoration." << std::endl;
}