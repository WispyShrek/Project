#include "Lily.h"

Lily::Lily() {
	this->strategy = new PartialSunCare();
	this->price = 70;
};

std::string Lily::getName() {
	return "Lily";
}

std::string Lily::getName() {
	return "Lily";
}

Lily* Lily::clone() {
	return new Lily(*this);
}

void Lily::print(){
	std::cout << "Lily" << std::endl;
}

double Lily::getPrice() {
	return price;
}

Lily::Lily(Lily& toCopy)  : Plant(toCopy) {}
