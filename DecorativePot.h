#ifndef DECORATIVEPOT_H
#define DECORATIVEPOT_H
#include "Customisation.h"

/**
 * @class DecorativePot
 * @brief A concrete decorator for adding a decorative pot to a Plant.
 *
 * This class is part of the Decorator design pattern. It inherits from the
 * abstract decorator `Customisation` and wraps a `Plant` object to add
 * the functionality of a decorative pot, which includes increasing its price.
 */
class DecorativePot : public Customisation {

private:
  /**
   * @var bool addedPot
   * @brief A flag indicating if the decorative pot has been added.
   */
  bool addedPot;
public:
  /**
   * @brief Sets the flag indicating if a pot has been added.
   * @param addedPot The new boolean value for the flag.
   */
  void setAddedPot(bool addedPot) { this->addedPot = addedPot; }
  /**
   * @brief Gets the flag indicating if a pot has been added.
   * @return True if the pot has been added, false otherwise.
   */
  bool getAddedPot() const { return addedPot; }
  /**
   * @brief Increases the price of the wrapped plant to account for the decorative pot.
   * This method delegates to the wrapped plant and adds the cost of the pot.
   */
  void increasePrice();
  /**
   * @brief Associates a customer with the wrapped plant.
   * This method delegates the call to the underlying `Plant` object.
   * @param customer A pointer to the Customer object.
   */
  void addCust(Customer *customer);
};

#endif
