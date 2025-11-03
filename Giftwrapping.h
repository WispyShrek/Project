#ifndef GIFTWRAPPING_H
#define GIFTWRAPPING_H
#include "Customisation.h"
/// @brief Represents a giftwrapping decoration for a plant.
/// Inherits from Customisation and adds giftwrapping-specific behavior.
class Giftwrapping : public Customisation
{
private:
  /// @brief Tracks whether giftwrapping has been added.
  bool addedWrapping;

public:
  /// @brief Sets the giftwrapping flag.
  /// @param addedWrapping Boolean indicating if giftwrapping was added.
  void setAddedWrapping(bool addedWrapping) { this->addedWrapping = addedWrapping; }
  /// @brief Gets the giftwrapping flag.
  /// @return True if giftwrapping was added, false otherwise.
  bool getAddedWrapping() const { return addedWrapping; }
  /// @brief Increases the price of the plant by the cost of giftwrapping.
  void increasePrice();
  /// @brief Associates a customer with the decorated plant.
  /// @param customer Pointer to the Customer object.
  void addCust(Customer *customer);
  /// @brief Prints the plant details along with giftwrapping info.
  void print();
  /// @brief Returns the name of the decoration.
  /// @return String "Giftwrapping".
  std::string getName() override { return "Giftwrapping"; }
  /// @brief Creates a copy of the Giftwrapping object.
  /// @return Pointer to a new Giftwrapping object.
  Plant *clone() override { return new Giftwrapping(*this); }
};
#endif