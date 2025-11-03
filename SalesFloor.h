#ifndef SALESFLOOR_H
#define SALESFLOOR_H
#include "Customer.h"
#include "Inventory.h"
#include <vector>
class Customer;
/// @brief Abstract base class representing a sales floor in the nursery.
/// Manages inventory and handles customer notifications.
class SalesFloor
{
public:
  /// @brief Notifies the sales floor about a customer's interest in a plant.
  /// @param customer Pointer to the Customer object.
  /// @param plant Pointer to the Plant object.
  /// @return True if the plant is available and processed; false otherwise.
  virtual bool notify(Customer *customer, Plant *plant) = 0;
  /// @brief Default constructor.
  SalesFloor() {}
  /// @brief Virtual destructor.
  virtual ~SalesFloor() = default;
  /// @brief Provides access to the inventory managed by the sales floor.
  /// @return Pointer to the Inventory object.
  Inventory *getInventory() { return &inventory; }

private:
  /// @brief Inventory of plants available on the sales floor.
  Inventory inventory;
};

#endif
