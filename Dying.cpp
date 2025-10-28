#include "Dying.h"

void Dying::next(Plant* context) {
	// TODO - implement Dying::next
	return;
}

PlantState* Dying::clone() const {
    return new Dying(*this);
}

void Dying::print() {
	std::cout << "This plant is dying, apply care to it" << std::endl;
}
