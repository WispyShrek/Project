#include "Mature.h"

void Mature::next(Plant* context) {
	// TODO - implement Mature::next
	return; 
}

PlantState* Mature::clone() const {
    return new Mature(*this);
}

