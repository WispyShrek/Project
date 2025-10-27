#include "Mature.h"

void Mature::next(Plant* context) {
    if (!context) return;
    std::cout << "Cannot grow more — already Mature.\n";
}

void Mature::print() {	
	std::cout << "The is a plant that is now Mature" << std::endl;
}

