#include "Rose.h"

Rose::Rose(){
	this->strategy = new SunnyCare();
	this->price = 80;
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

double Rose::getPrice() {
	return price;
}

Rose::Rose(Rose& toCopy) : Plant(toCopy) {}