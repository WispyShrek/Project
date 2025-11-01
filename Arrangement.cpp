#include "Arrangement.h"
// Default constructor and destructor can be omitted if not needed
void Arrangement::increasePrice()//increases price by 150 for arrangement
{
	plant->increasePrice(150);
}

void Arrangement::addCust(Customer *customer)//adds the customer to the plant's customer pointer
{
	plant->addCust(customer);//delegation
}
