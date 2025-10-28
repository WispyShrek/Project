#include "Rose.h"

Rose::Rose(){
	this->strategy = new SunnyCare();
};

std::string Rose::getName() {
	return "Rose";
}

Rose* Rose::clone() {
	return new Rose(*this);
}

void Rose::print(){
	std::cout << "Rose" << std::endl;
}

Rose::Rose(Rose& toCopy) : Plant(toCopy) {}
