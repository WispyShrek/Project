#include "DecorativePot.h"

void DecorativePot::increasePrice()
{
	plant->increasePrice(200);
}

void DecorativePot::addCust(Customer *customer)
{
	plant->addCust(customer);
}
