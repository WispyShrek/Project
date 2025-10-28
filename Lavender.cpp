#include "Lavender.h"

Lavender::Lavender(){
	this->strategy = new PartialSunCare();
}

std::string Lavender::getName() {
	return "Lavender";
}

Lavender* Lavender::clone() {
	return new Lavender(*this);
}

void Lavender::print(){
	std::cout << "Lavender" << std::endl;
}

Lavender::Lavender(Lavender& toCopy) : Plant(toCopy) {}
