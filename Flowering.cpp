#include "Flowering.h"

void Flowering::next(Plant* context) {
    if (!context) return;
    context->setState(new Mature());
	// TODO - implement Flowering::next
	return;
}

PlantState* Flowering::clone() const {
    return new Flowering(*this);
}

void Flowering::print() {
	std::cout << "This is a plant that is flowering" << std::endl;
}
