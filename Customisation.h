#ifndef CUSTOMISATION_H
#define CUSTOMISATION_H
#include "Plant.h"
/// @brief Abstract base class for plant customisations (decorators).
/// Inherits from Plant and wraps another Plant object to add features like decorations.
class Customisation : public Plant
{
public:
  /// @brief Pointer to the underlying Plant being decorated.
  Plant *plant;
  /// @brief Pure virtual method to increase the price of the decorated plant.
  virtual void increasePrice() = 0;
  /// @brief Pure virtual method to associate a customer with the decorated plant.
  /// @param customer Pointer to the Customer object.
  virtual void addCust(Customer *customer) = 0;
};

#endif
