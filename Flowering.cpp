#include "Flowering.h"

void Flowering::next(Plant* context) {
    if (!context) return;
    context->setState(new Mature());
}

void Flowering::print() {
	std::cout << "This is a plant that is flowering" << std::endl;
}
