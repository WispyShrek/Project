#include "Sprout.h"

void Sprout::next(Plant* context) {
	// TODO - implement Sprout::next
	return;
}

PlantState* Sprout::clone() const {
    return new Sprout(*this);
}

