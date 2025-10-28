#include "Sprout.h"

void Sprout::next(Plant* context) {
    if (!context) return;
    context->setState(new Flowering());
}

void Sprout::print() {
	std::cout << "This is a sprout" << std::endl;
	// TODO - implement Sprout::next
	return;
}

PlantState* Sprout::clone() const {
    return new Sprout(*this);
}

