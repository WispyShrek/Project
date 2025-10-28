#include "Tulip.h"

Tulip::Tulip() = default;

std::string Tulip::getName() {
	return "Tulip";
}

Tulip* Tulip::clone() {
	return new Tulip(*this);
}

void Tulip::print(){
	std::cout << "Tulip" << std::endl;
}

Tulip::Tulip(Tulip& toCopy) : Plant(toCopy) {}
