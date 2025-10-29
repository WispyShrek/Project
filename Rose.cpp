#include "Rose.h"

Rose::Rose(){
	this->strategy = new SunnyCare();
	this->price = 80;
};

std::string Rose::getName() {
	return "Rose";
}

double Rose::getPrice() {
	return price;
}

Rose* Rose::clone() {
	return new Rose(*this);
}

void Rose::print(){
	std::cout << "Rose" << std::endl;
}

Rose::Rose(Rose& toCopy) : Plant(toCopy) {}
