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
	for (int i = 0; i < cart.size(); i++) {
		delete cart[i];
		cart[i] = NULL;
	}
}
void Customer::changed() {
	salesFloor->notify(this);
}
void Customer::addToCart(Plant* plant) {
	cart.push_back(plant);
}
string Customer::cartToString() {
	string cartContents = "Cart Contents:\n";
	int count=0;
	for (int i = 0; i < cart.size(); i++) {
		count++;
		cartContents += "- Plant " + to_string(i + 1) + ": " + cart[i]->getName() + "\n" + "\t Colour: " + cart[i]->getColour() + "\n" + "\t Scent: " + cart[i]->getScent() + "\n" + "\t Price: " + cart[i]->getPrice() + "\n";
	}
	cartContents += "Total Plants: " + to_string(count) + "\n";
	return cartContents;
}
