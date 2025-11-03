#include "DecorativePot.h"

/// @brief Increases the price of the plant by 200 units.
/// This method applies the cost of the decorative pot decoration.
void DecorativePot::increasePrice() {
  plant->increasePrice(200); // increase price by 200 for decorative pot
}

/**
 * @brief Delegates the `addCust` call to the wrapped `Plant` object.
 * @param customer A pointer to the Customer to be associated with the plant.
 */
void DecorativePot::addCust(Customer *customer)
{
	plant->addCust(customer);
}
