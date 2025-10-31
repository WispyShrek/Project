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



#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Rose: Test Rose class methods") {
	Rose rose;

	// Test getName method
	REQUIRE(rose.getName() == "Rose");

	// Test getPrice method
	REQUIRE(rose.getPrice() == 80);

	// Test clone method
	Rose* clonedRose = rose.clone();
	REQUIRE(clonedRose != nullptr);
	REQUIRE(clonedRose->getName() == "Rose");
	REQUIRE(clonedRose->getPrice() == 80);
	delete clonedRose;

	// Test print method (just ensure it runs without error)
	rose.print();
}
#endif