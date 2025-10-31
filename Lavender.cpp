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

Lavender::Lavender(Lavender& toCopy) : Plant(toCopy) {
	this->price = toCopy.price;
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Lavender: Test Lavender class methods") {
	Lavender lavender;

	// Test getName method
	REQUIRE(lavender.getName() == "Lavender");

	// Test getPrice method
	REQUIRE(lavender.getPrice() == 60);

	// Test clone method
	Lavender* clonedLavender = lavender.clone();
	REQUIRE(clonedLavender != nullptr);
	REQUIRE(clonedLavender->getName() == "Lavender");
	REQUIRE(clonedLavender->getPrice() == 60);
	delete clonedLavender;

	// Test print method (just ensure it runs without error)
	lavender.print();
}
#endif
