#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H
#include "Customisation.h"
/**
 * @class Arrangement
 * @brief A concrete decorator for adding a floral arrangement to a Plant.
 *
 * This class is part of the Decorator design pattern. It inherits from the
 * abstract decorator `Customisation` and wraps a `Plant` object to add
 * the functionality of a floral arrangement, which includes increasing its price.
 */
class Arrangement : public Customisation
{
private:
  /**
   * @var bool addedArrangement
   * @brief A flag indicating if the arrangement has been added.
   */
  bool addedArrangement;
public:
  /**
   * @brief Sets the flag indicating if an arrangement has been added.
   * @param addedArrangement The new boolean value for the flag.
   */
  void setAddedArrangement(bool addedArrangement) { this->addedArrangement= addedArrangement; }
  /**
   * @brief Gets the flag indicating if an arrangement has been added.
   * @return True if the arrangement has been added, false otherwise.
   */
  bool getAddedArrangement() const { return addedArrangement; }
  /**
   * @brief Increases the price of the wrapped plant to account for the arrangement.
   * This method delegates to the wrapped plant and adds the cost of the arrangement.
   */
  void increasePrice();
  /**
   * @brief Associates a customer with the wrapped plant.
   * This method delegates the call to the underlying `Plant` object.
   * @param customer A pointer to the Customer object.
   */
  void addCust(Customer* customer);
};

#endif
