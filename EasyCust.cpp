#include "EasyCust.h"

EasyCust::EasyCust(std::string name, SalesFloor *salesFloor, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants)
	: Customer(name, salesFloor)
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
  void EasyCust::pay(){
	this->paymentStrategy->pay();
  }
  string EasyCust::voiceLine() {
	return "I'm a easy customer";
  }
