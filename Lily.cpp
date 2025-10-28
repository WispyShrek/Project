#include "Lily.h"

Lily::Lily() = default;

std::string Lily::getName() {
	return "Lily";
}

Lily* Lily::clone() {
	return new Lily(*this);
}

void Lily::print(){
	std::cout << "Lily" << std::endl;
}

Lily::Lily(Lily& toCopy)  : Plant(toCopy) {}
