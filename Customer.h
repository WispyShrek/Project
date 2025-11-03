#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Arrangement.h"
#include "Customisation.h"
#include "DecorativePot.h"
#include "Giftwrapping.h"
#include "PaymentStrategy.h"
#include "Plant.h"
#include "SalesFloor.h"
#include <string>
#include <vector>
using namespace std;

/// @brief Represents a customer interacting with the sales floor and managing a
/// cart of plants. This is an abstract base class with virtual methods for
/// customization.
class Customer {
private: // attributes
  /// @brief The customer's shopping cart containing Plant pointers.
  vector<Plant *> cart;
  /// @brief Pointer to the SalesFloor the customer interacts with.
  SalesFloor *salesFloor;
  /// @brief Name of the customer.
  string name;
  /// @brief Time available for shopping, in minutes.
  double timeAvailable;

public: /// @brief Default constructor.
  Customer();
  /// @brief Parameterized constructor.
  /// @param name Name of the customer.
  /// @param salesFloor Pointer to the SalesFloor object.
  /// @param timeAvailable Time available for shopping in minutes.
  Customer(std::string name, SalesFloor *salesFloor, double timeAvailable);
  /// @brief Virtual destructor.
  virtual ~Customer();
  /// @brief Abstract method for customer-specific voice line.
  /// @return A string representing the customer's voice line.
  virtual string voiceLine() = 0;
  /// @brief Gets a string representing the customer's time availability.
  /// @return A formatted string of available time.
  string getTimeLine();
  /// @brief Adds a decoration to a plant in the cart.
  /// @param customisation pointer for the plant.
  /// @param plant Pointer to the plant to decorate.
  void addDecoration(Customisation *decorator, Plant *plant);
  /// @brief Adds a plant to the customer's cart.
  /// @param plant Pointer to the Plant object.
  void addToCart(Plant *plant);
  /// @brief Removes a plant from the customer's cart.
  /// @param plant Pointer to the Plant object to remove.
  void removeFromCart(Plant *plant);
  /// @brief Returns a string representation of the cart contents.
  /// @return Formatted string listing all plants in the cart.
  string cartToString();
  /// @brief Abstract method for customer to enquire about plants.
  /// @param salesFloor Pointer to the SalesFloor to enquire from.
  virtual void enquirePlants(SalesFloor *salesFloor) = 0;
};

#endif
