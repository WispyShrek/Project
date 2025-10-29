#include "Tulip.h"

Tulip::Tulip(){
	this->strategy = new ShadyCare();
	this->price = 65;
};

std::string Tulip::getName() {
	return "Tulip";
}

double Tulip::getPrice() {
	return price;
}

Tulip* Tulip::clone() {
	return new Tulip(*this);
}

void Tulip::print(){
	std::cout << "Tulip" << std::endl;
}

Tulip::Tulip(Tulip& toCopy) : Plant(toCopy) {}
