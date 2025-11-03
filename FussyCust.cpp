#include "FussyCust.h"
/// @brief Default constructor for FussyCust.
FussyCust::FussyCust() {}
/// @brief Parameterized constructor for FussyCust.
/// @param name Name of the customer.
/// @param salesFloor Pointer to the SalesFloor object.
/// @param timeAvailable Time available for shopping.
/// @param paymentStrategy Pointer to the PaymentStrategy used by the customer.
/// @param preferredPlants Vector of preferred Plant pointers.
FussyCust::FussyCust(std::string name, SalesFloor *salesFloor, double timeAvailable, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants)
	: Customer(name, salesFloor, timeAvailable)
{
	// Additional initialization if needed
	this->paymentStrategy = paymentStrategy;
	this->preferredPlants = preferredPlants;
}
/// @brief Destructor for FussyCust.
FussyCust::~FussyCust() {}
/// @brief Executes the customer's payment strategy.
void FussyCust::pay()
{
	this->paymentStrategy->pay();
}
/// @brief Returns a voice line specific to FussyCust.
/// @return A string representing the customer's voice line.
string FussyCust::voiceLine()
{
	return "I'm a fussy customer";
}
/// @brief Enquires about preferred plants from the sales floor.
/// If a preferred plant is available, adds it to the cart and removes it from preferences.
/// @param salesFloor Pointer to the SalesFloor object.
void FussyCust::enquirePlants(SalesFloor *salesFloor)
{
	for (int i = 0; i < int(preferredPlants.size()); i++)
	{
		bool got = salesFloor->notify(this, preferredPlants[i]);
		if (got)
		{
			preferredPlants.erase(preferredPlants.begin() + i);
			addToCart(preferredPlants[i]);
			break;
		}
		else
		{
			break;
		}
	}
	pay();
}