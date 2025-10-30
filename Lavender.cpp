#include "Lavender.h"

Lavender::Lavender() {
	this->strategy = new PartialSunCare();
	this->price = 60;
};

std::string Lavender::getName() {
	return "Lavender";
}

Lavender* Lavender::clone() {
	return new Lavender(*this);
}

void Lavender::print(){
	std::cout << "Lavender" << std::endl;
}

double Lavender::getPrice() {
	return price;
}

Lavender::Lavender(Lavender& toCopy) : Plant(toCopy) {}
