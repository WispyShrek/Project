#include "Customer.h"
// Default constructor and destructor can be omitted if not needed
//
Customer::Customer()
{ // default constructor
	name = "";
	salesFloor = NULL;
}
Customer::Customer(std::string name, SalesFloor *salesFloor)
{ // constructor
	this->name = name;
	this->salesFloor = salesFloor;
}

Customer::~Customer()
{ // destructor
	for (int i = 0; i < int(cart.size()); i++)
	{ // delete plants in cart
		delete cart[i];
		cart[i] = NULL;
	}
	delete salesFloor;
	salesFloor = NULL;

}

void Customer::enquirePlants(SalesFloor *salesFloor)
{ // notifies salesfloor that customer is enquiring about plants
	salesFloor->notify(this);
}
void Customer::addDecoration(Plant *plant)
{ // adds decoration to plant if not already in cart
	for (int i = 0; i < int(cart.size()); i++)
	{
		if (cart[i]->getName() == plant->getName())
		{

			return;
		}
	}
}
void Customer::addToCart(Plant *plant)
{ // adds plant to cart
	cart.push_back(plant);
}
string Customer::cartToString()
{ // returns string representation of cart
	string cartContents = "Cart Contents:\n";
	int count = 0;
	for (int i = 0; i < int(cart.size()); i++)
	{
		count++;
		std::cout << i << std::endl;
		cartContents += "- Plant " + to_string(i + 1) + ": " + cart[i]->getName() + "\n" + "\t Colour: " + cart[i]->getColour() + "\n" + "\t Scent: " + cart[i]->getScent() + "\n" + "\t Price: " + cart[i]->getPrice() + "\n";
	}
	cartContents += "Total Plants: " + to_string(count) + "\n";
	return cartContents;
}
