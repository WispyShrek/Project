#include "Dying.h"

void Dying::next(Plant* context) {
	// TODO - implement Dying::next
	return;
}

PlantState* Dying::clone() const {
    return new Dying(*this);
}

