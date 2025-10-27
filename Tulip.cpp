#include "Tulip.h"

Tulip::Tulip() = default;

Tulip* Tulip::clone() {
	return new Tulip(*this);
}

void Tulip::print(){
	std::cout << "Tulip" << std::endl;
}

Tulip::Tulip(Tulip& toCopy) : Plant(toCopy) {}
