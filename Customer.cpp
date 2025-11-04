#include "Customer.h"
#include <cmath>

/// @brief Default constructor for Customer.
/// Initializes name to empty string and salesFloor to NULL.
Customer::Customer() { // default constructor
  name = "";
  salesFloor = NULL;
}

/// @brief Parameterized constructor for Customer.
/// @param name Name of the customer.
/// @param salesFloor Pointer to the SalesFloor object.
/// @param time Time available for the customer.
Customer::Customer(std::string name, SalesFloor *salesFloor,
                   double time) { // constructor
  this->timeAvailable = time;
  this->name = name;
  this->salesFloor = salesFloor;
}
/// @brief Destructor for Customer.
/// Deletes all dynamically allocated Plant objects in the cart.
Customer::~Customer() {                        // destructor
  for (int i = 0; i < int(cart.size()); i++) { // delete plants in cart
    delete cart[i];
    cart[i] = NULL;
  }
}
/// @brief Adds a decoration to a plant in the cart.
/// @param decorationType Type of decoration ("arrangement",
/// "giftwrapping", "decorativepot").
/// @param plant Pointer to the plant to decorate.
void Customer::addDecoration(Customisation *decorator, Plant *plant) {
  // Find the plant in cart
  for (int i = 0; i < int(cart.size()); i++) {
    if (cart[i]->getName() == plant->getName()) {
      // Found it - now wrap it with the requested decoration
      decorator->plant = cart[i]; // Wrap existing plant
      cart[i] = decorator;        // Replace with decorated version
      decorator->increasePrice(); // Apply price increase
      return;
    }
  }
}
/// @brief Adds a plant to the customer's cart.
/// @param plant Pointer to the Plant object to add.
void Customer::addToCart(Plant *plant) { // adds plant to cart
  cart.push_back(plant);
}
/// @brief Returns a string representation of the cart contents.
/// Includes plant name, colour, scent, and price.
/// @return Formatted string listing all plants in the cart.

string Customer::cartToString() { // returns string representation of cart
  string cartContents = "Cart Contents:\n";
  int count = 0;
  for (int i = 0; i < int(cart.size()); i++) {
    count++;
    cartContents += "- Plant " + to_string(i + 1) + ": " + cart[i]->getName() +
                    "\n" + "\t Colour: " + cart[i]->getColour() + "\n" +
                    "\t Scent: " + cart[i]->getScent() + "\n" + "\t Price: " +
                    std::to_string(std::round(cart[i]->getPrice())) + "\n";
  }
  cartContents += "Total Plants: " + to_string(count) + "\n";
  return cartContents;
}
// #ifdef ENABLE_DOCTESTS
// #include "Customer.h"
// #include "EFT.h"
// #include "EasyCust.h"
// #include "Rose.h"
// #include "doctest.h"
// #include <sstream>

// TEST_SUITE("Customer") {

//   TEST_CASE("addToCart and cartToString reflect added plant") {
//     EasyCust customer("Alice", nullptr, 10.0, new EFT(), {});
//     Rose *rose = new Rose();
//     customer.addToCart(rose);

//     std::string cart = customer.cartToString();
//     CHECK(cart.find("Rose") != std::string::npos);
//     CHECK(cart.find("Colour") != std::string::npos);
//     CHECK(cart.find("Scent") != std::string::npos);
//     CHECK(cart.find("Price") != std::string::npos);
//   }

//   TEST_CASE("addDecoration: arrangement increases price by 150") {
//     EasyCust customer("Bob", nullptr, 10.0, new EFT(), {});
//     Rose *rose = new Rose();
//     customer.addToCart(rose);

//     double originalPrice = rose->getPrice();
//     customer.addDecoration("arrangement", rose);

//     std::string cart = customer.cartToString();
//     CHECK(cart.find("Rose") != std::string::npos);
//     CHECK(cart.find(std::to_string(int(originalPrice + 150))) !=
//           std::string::npos);
//   }

//   TEST_CASE("addDecoration: giftwrapping increases price by 100") {
//     EasyCust customer("Carol", nullptr, 10.0, new EFT(), {});
//     Rose *rose = new Rose();
//     customer.addToCart(rose);

//     double originalPrice = rose->getPrice();
//     customer.addDecoration("giftwrapping", rose);

//     std::string cart = customer.cartToString();
//     CHECK(cart.find(std::to_string(int(originalPrice + 100))) !=
//           std::string::npos);
//   }

//   TEST_CASE("addDecoration: decorativepot increases price by 200") {
//     EasyCust customer("Dave", nullptr, 10.0, new EFT(), {});
//     Rose *rose = new Rose();
//     customer.addToCart(rose);

//     double originalPrice = rose->getPrice();
//     customer.addDecoration("decorativepot", rose);

//     std::string cart = customer.cartToString();
//     CHECK(cart.find(std::to_string(int(originalPrice + 200))) !=
//           std::string::npos);
//   }

//   TEST_CASE("addDecoration: unknown type does not crash") {
//     EasyCust customer("Eve", nullptr, 10.0, new EFT(), {});
//     Rose *rose = new Rose();
//     customer.addToCart(rose);

//     // Should print error but not crash
//     customer.addDecoration("ribbon", rose);
//     std::string cart = customer.cartToString();
//     CHECK(cart.find("Rose") != std::string::npos);
//   }

//   TEST_CASE("Destructor cleans up cart memory") {
//     EasyCust *customer = new EasyCust("Frank", nullptr, 10.0, new EFT(), {});
//     customer->addToCart(new Rose());
//     customer->addToCart(new Rose());
//     delete customer; // Should not leak or crash
//   }
// }
// #endif
