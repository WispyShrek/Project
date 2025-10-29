#include "Lily.h"

Lily::Lily(){
	this->strategy = new PartialSunCare();
	this->price = 70;
};

std::string Lily::getName() {
	return "Lily";
}

double Lily::getPrice() {
	return price;
}

Lily* Lily::clone() {
	return new Lily(*this);
}

void Lily::print(){
	std::cout << "Lily" << std::endl;
}

Lily::Lily(Lily& toCopy)  : Plant(toCopy) {}
