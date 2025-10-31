#include "Tulip.h"

Tulip::Tulip() {
	this->strategy = new ShadyCare();
	this->price = 50;
}

std::string Tulip::getName() {
	return "Tulip";
}

Tulip* Tulip::clone() {
	return new Tulip(*this);
}

void Tulip::print(){
	std::cout << "Tulip" << std::endl;
}

double Tulip::getPrice() {
	return price;
}

Tulip::Tulip(Tulip& toCopy) : Plant(toCopy) {}
