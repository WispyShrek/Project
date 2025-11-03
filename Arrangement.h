#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H
#include "Customisation.h"
/// @brief Represents an arrangement decoration for a plant.
/// Inherits from Customisation and adds arrangement-specific behavior.
class Arrangement : public Customisation {
private:
  /// @brief Tracks whether the arrangement has been added.
  bool addedArrangement; // to track if arrangement has been added
public:
  /// @brief Default constructor.
  /// Initializes the arrangement flag to false.
  Arrangement()
      : Customisation(), addedArrangement(false) {} // default constructor
  /// @brief Destructor.
  ~Arrangement();
  /// @brief Sets the arrangement flag.
  /// @param addedArrangement Boolean indicating if arrangement was added.
  void setAddedArrangement(bool addedArrangement) {
    this->addedArrangement = addedArrangement;
  } // setter
    /// @brief Gets the arrangement flag.
  /// @return True if arrangement was added, false otherwise.
  bool getAddedArrangement() const { return addedArrangement; } // getter
  /// @brief Increases the price of the plant by the arrangement cost.
  void increasePrice() override;
  /// @brief Associates a customer with the decorated plant.
  /// @param customer Pointer to the Customer object.
  void addCust(Customer *customer) override;
  /// @brief Prints the plant details along with arrangement info.
  std::string print() override;
  /// @brief Returns the name of the decoration.
  /// @return String "Arrangement".
  std::string getName() override { return "Arrangement"; }
  /// @brief Creates a copy of the Arrangement object.
  /// @return Pointer to a new Arrangement object.
  Plant *clone() override { return new Arrangement(*this); }
};

#endif
