#include "FussyCust.h"

FussyCust::FussyCust() {}
FussyCust::FussyCust(std::string name, SalesFloor *salesFloor, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants)
	: Customer(name, salesFloor)
{
	// Additional initialization if needed
	this->paymentStrategy = paymentStrategy;
	this->preferredPlants = preferredPlants;
}
FussyCust::~FussyCust() {}
void FussyCust::pay()
{
	this->paymentStrategy->pay();
}
string FussyCust::voiceLine()
{
	return "I'm a fussy customer";
}