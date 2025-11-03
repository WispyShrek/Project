#include "Arrangement.h"
#include <sstream>

/// @brief Destructor for Arrangement.
/// Cleans up any resources if needed (currently empty).
// Default constructor and destructor can be omitted if not needed
Arrangement::~Arrangement() {} // destructor
/// @brief Increases the price of the plant by 150 units.
/// This method applies the cost of the arrangement decoration.
void Arrangement::increasePrice() // increases price by 150 for arrangement
{
  plant->increasePrice(150);
}
/// @brief Associates a customer with the decorated plant.
/// Delegates the customer assignment to the underlying plant.
/// @param customer Pointer to the Customer object.
void Arrangement::addCust(
    Customer *customer) // adds the customer to the plant's customer pointer
{
  plant->addCust(customer); // delegation
}
/// @brief Prints the details of the plant with arrangement decoration.
/// Outputs the base plant details followed by arrangement info.
std::string Arrangement::print() // prints arrangement details
{
  std::stringstream arrangement;
  arrangement << "Arrangement Details: " << std::endl;
  arrangement << plant->print();
  arrangement << "\nwith Arrangement decoration." << std::endl;
  return arrangement.str();
}
#ifdef ENABLE_DOCTESTS
#include "Arrangement.h"
#include "EFT.h"
#include "EasyCust.h"
#include "Rose.h"
#include "doctest.h"
#include <sstream>

TEST_SUITE("Arrangement") {

  TEST_CASE("increasePrice adds 150 to Rose") {
    Rose *rose = new Rose();
    Arrangement *decorated = new Arrangement();
    decorated->plant = rose;

    double originalPrice = rose->getPrice();
    decorated->increasePrice();
    double newPrice = rose->getPrice();

    CHECK(newPrice == doctest::Approx(originalPrice + 150.0));
    delete decorated;
  }

  TEST_CASE("addCust delegates to Rose") {
    EasyCust *customer = new EasyCust("Lily", nullptr, 10.0, new EFT(), {});
    Rose *rose = new Rose();
    Arrangement *decorated = new Arrangement();
    decorated->plant = rose;

    decorated->addCust(customer); // should not crash
    delete decorated;
    delete customer;
  }

  TEST_CASE("print outputs correct decoration info") {
    Rose *rose = new Rose();
    Arrangement *decorated = new Arrangement();
    decorated->plant = rose;

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    decorated->print();

    std::cout.rdbuf(oldCout); // restore

    std::string printed = output.str();
    CHECK(printed.find("Arrangement Details:") != std::string::npos);
    CHECK(printed.find("with Arrangement decoration.") != std::string::npos);
    CHECK(printed.find("Rose") != std::string::npos);

    delete decorated;
  }
}
#endif
