#include "Lily.h"

Lily::Lily() = default;

Lily* Lily::clone() {
	return new Lily(*this);
}

void Lily::print(){
	std::cout << "Lily" << std::endl;
}

Lily::Lily(Lily& toCopy)  : Plant(toCopy) {}
