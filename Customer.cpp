#include "Customer.h"
// Default constructor and destructor can be omitted if not needed
//
Customer::Customer()
{ // default constructor
	name = "";
	salesFloor = NULL;
}
Customer::Customer(std::string name, SalesFloor *salesFloor, double time)
{ // constructor
	this->timeAvailable = time;
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
}


void Customer::addDecoration(std::string decorationType, Plant *plant)
{
	// Find the plant in cart
	for (int i = 0; i < int(cart.size()); i++)
	{
		if (cart[i]->getName() == plant->getName())
		{
			// Found it - now wrap it with the requested decoration
			Customisation *decorator = nullptr;

			if (decorationType == "arrangement")
			{
				decorator = new Arrangement();
			}
			else if (decorationType == "giftwrapping")
			{
				decorator = new Giftwrapping();
			}
			else if (decorationType == "decorativepot")
			{
				decorator = new DecorativePot();
			}
			else
			{
				std::cout << "Unknown decoration type!\n";
				return;
			}

			decorator->plant = cart[i]; // Wrap existing plant
			cart[i] = decorator;		// Replace with decorated version
			decorator->increasePrice(); // Apply price increase
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
		cartContents += "- Plant " + to_string(i + 1) + ": " + cart[i]->getName() + "\n" + "\t Colour: " + cart[i]->getColour() + "\n" + "\t Scent: " + cart[i]->getScent() + "\n" + "\t Price: " + cart[i]->getPrice() + "\n";
	}
	cartContents += "Total Plants: " + to_string(count) + "\n";
	return cartContents;
}
