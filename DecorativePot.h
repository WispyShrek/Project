/**
 * @file DecorativePot.h
 * @brief Defines the DecorativePot concrete decorator class.
 */
#ifndef DECORATIVEPOT_H
#define DECORATIVEPOT_H
#include "Customisation.h"
/// @brief Represents a decorative pot customisation for a plant.
/// Inherits from Customisation and adds decorative pot-specific behavior.
class DecorativePot : public Customisation {
private:
  /// @brief Tracks whether the decorative pot has been added.
  bool addedPot;

public:
  /// @brief Sets the decorative pot flag.
  /// @param addedPot Boolean indicating if the pot was added.
  void setAddedPot(bool addedPot) { this->addedPot = addedPot; }
  /// @brief Gets the decorative pot flag.
  /// @return True if the pot was added, false otherwise.
  bool getAddedPot() const { return addedPot; }
  /// @brief Increases the price of the plant by the cost of the decorative pot.
  void increasePrice() override;
  /// @brief Associates a customer with the decorated plant.
  /// @param customer Pointer to the Customer object.
  void addCust(Customer *customer) override;
  /// @brief Prints the plant details along with decorative pot info.
  std::string print() override;

  /// @brief Returns the name of the decoration.
  /// @return String "DecorativePot".
  std::string getName() override { return "DecorativePot"; }
  /// @brief Creates a copy of the DecorativePot object.
  /// @return Pointer to a new DecorativePot object.
  Plant *clone() override { return new DecorativePot(*this); }
};

#endif
