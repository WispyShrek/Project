#include "Lavender.h"

Lavender::Lavender(){
	this->strategy = new PartialSunCare();
	this->price = 50;
}

std::string Lavender::getName() {
	return "Lavender";
}

double Lavender::getPrice() {
	return price;
}

Lavender* Lavender::clone() {
	return new Lavender(*this);
}

void Lavender::print(){
	std::cout << "Lavender" << std::endl;
}

Lavender::Lavender(Lavender& toCopy) : Plant(toCopy) {}
