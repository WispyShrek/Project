#include "Lavender.h"

Lavender::Lavender() = default;

Lavender* Lavender::clone() {
	return new Lavender(*this);
}

void Lavender::print(){
	std::cout << "Lavender" << std::endl;
}

Lavender::Lavender(Lavender& toCopy) : Plant(toCopy) {}
