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
