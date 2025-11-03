#include "EasyCust.h"
/// @brief Constructs an EasyCust object with name, sales floor, time, payment strategy, and preferred plants.
/// @param name Name of the customer.
/// @param salesFloor Pointer to the SalesFloor object.
/// @param t Time available for shopping.
/// @param paymentStrategy Pointer to the PaymentStrategy used by the customer.
/// @param preferredPlants Vector of preferred Plant pointers.
EasyCust::EasyCust(std::string name, SalesFloor *salesFloor, double t, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants)
	: Customer(name, salesFloor, t)
{
	// Additional initialization if needed
	this->paymentStrategy = paymentStrategy;
	this->preferredPlants = preferredPlants;
}
/// @brief Destructor for EasyCust.
/// Cleans up dynamically allocated preferred plants and payment strategy.
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
/// @brief Executes the customer's payment strategy.
void EasyCust::pay()
{
	this->paymentStrategy->pay();
}
/// @brief Returns a voice line specific to EasyCust.
/// @return A string representing the customer's voice line.
string EasyCust::voiceLine()
{
	return "I'm a easy customer";
}
/// @brief Enquires about preferred plants from the sales floor.
/// If a preferred plant is available, adds it to the cart and removes it from preferences.
/// @param salesFloor Pointer to the SalesFloor object.
void EasyCust::enquirePlants(SalesFloor *salesFloor)
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
#ifdef ENABLE_DOCTESTS
#include "doctest.h"
#include "EasyCust.h"
#include "Rose.h"
#include "EFT.h"
#include "SalesFloor.h"
#include <sstream>

// Concrete SalesFloor that always returns true for notify
class AlwaysAvailableFloor : public SalesFloor
{
public:
	bool notify(Customer *customer, Plant *plant) override
	{
		return true; // simulate successful acquisition
	}
};

TEST_CASE("EasyCust: voiceLine returns expected string")
{
	EasyCust customer("Alice", nullptr, 10.0, new EFT(), {});
	CHECK(customer.voiceLine() == "I'm a easy customer");
}

TEST_CASE("EasyCust: pay invokes EFT strategy")
{
	EFT *eft = new EFT();
	EasyCust customer("Bob", nullptr, 5.0, eft, {});

	std::stringstream ss;
	std::streambuf *old_buf = std::cout.rdbuf(ss.rdbuf());
	customer.pay();
	std::cout.rdbuf(old_buf);

	CHECK(ss.str() == "Paying with EFT");
}

TEST_CASE("EasyCust: enquirePlants adds plant to cart and pays")
{
	Rose *rose = new Rose();
	std::vector<Plant *> prefs = {rose};
	EFT *eft = new EFT();
	AlwaysAvailableFloor *floor = new AlwaysAvailableFloor();

	EasyCust customer("Carol", floor, 15.0, eft, prefs);

	std::stringstream ss;
	std::streambuf *old_buf = std::cout.rdbuf(ss.rdbuf());
	customer.enquirePlants(floor);
	std::cout.rdbuf(old_buf);

void EasyCust::get() {
}

void EasyCust::set() {
}
#endif