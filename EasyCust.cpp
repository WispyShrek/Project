#include "EasyCust.h"

EasyCust::EasyCust(std::string name, SalesFloor *salesFloor, double t, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants)
	: Customer(name, salesFloor, t)
{
	// Additional initialization if needed
	this->paymentStrategy = paymentStrategy;
	this->preferredPlants = preferredPlants;
}
EasyCust::~EasyCust()
{
	for (int i = 0; i < int(preferredPlants.size()); i++)
	{
		delete preferredPlants[i];
		preferredPlants[i] = NULL;
	}
	delete paymentStrategy;
	paymentStrategy = NULL;
}
void EasyCust::pay()
{
	this->paymentStrategy->pay();
}
string EasyCust::voiceLine()
{
	return "I'm a easy customer";
}
void EasyCust::enquirePlants(SalesFloor *salesFloor)
{
	for (int i = 0; i < int(preferredPlants.size()); i++)
	{
		salesFloor->notify(this, preferredPlants[i]);
	}
}
