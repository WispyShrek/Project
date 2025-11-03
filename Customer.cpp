#include "Customer.h"

Customer::Customer() {
	name = "";
	salesFloor = NULL;
	
}
Customer::Customer(std::string name, SalesFloor* salesFloor) {
	this->name = name;
	this->salesFloor = salesFloor;
}

Customer::~Customer() {
	for (int i = 0; i <  int(cart.size()); i++) {
		delete cart[i];
		cart[i] = NULL;
	}
}
void Customer::changed() {
	salesFloor->notify(this);
}
void Customer::addDecoration(Plant* plant) {
	for (int i = 0; i <  int(cart.size()); i++) {
		if (*cart[i] == *plant) {
			
			return;
		}
	}
}
void Customer::addToCart(Plant* plant) {
	cart.push_back(plant);
}
string Customer::cartToString() {
	string cartContents = "Cart Contents:\n";
	int count=0;
	for (int i = 0; i < int(cart.size()); i++) {
		count++;
		std::cout << i << std::endl;
		cartContents += "- Plant " + to_string(i + 1) + ": " + cart[i]->getName() + "\n" + "\t Colour: " + cart[i]->getColour() + "\n" + "\t Scent: " + cart[i]->getScent() + "\n" + "\t Price: " + to_string(cart[i]->getPrice()) + "\n";
	}
	cartContents += "Total Plants: " + to_string(count) + "\n";
	return cartContents;
}
