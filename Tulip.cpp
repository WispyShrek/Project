#include "Tulip.h"

Tulip::Tulip() {
	this->strategy = new ShadyCare();
	this->price = 50;
}

std::string Tulip::getName() {
	return "Tulip";
}

Tulip* Tulip::clone() {
	return new Tulip(*this);
}

void Tulip::print(){
	std::cout << "Tulip" << std::endl;
}

double Tulip::getPrice() {
	return price;
}

Tulip::Tulip(Tulip& toCopy) : Plant(toCopy) {
	this->price = toCopy.price;
}



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Tulip: Test Tulip class methods") {
	Tulip tulip;

	// Test getName method
	REQUIRE(tulip.getName() == "Tulip");

	// Test getPrice method
	REQUIRE(tulip.getPrice() == 50);

	// Test clone method
	Tulip* clonedTulip = tulip.clone();
	REQUIRE(clonedTulip != nullptr);
	REQUIRE(clonedTulip->getName() == "Tulip");
	REQUIRE(clonedTulip->getPrice() == 50);
	delete clonedTulip;

	// Test print method (just ensure it runs without error)
	tulip.print();
}
#endif