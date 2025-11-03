#include "Arrangement.h"

/**
 * @brief Increases the price of the wrapped plant by a fixed amount for the arrangement.
 *
 * This method is an implementation of the decorator functionality. It calls the
 * "increasePrice" method on the wrapped "Plant" object, adding the cost
 * specific to this arrangement (150).
 */
void Arrangement::increasePrice()
{
	plant->increasePrice(150);
}

/**
 * @brief Delegates the "addCust" call to the wrapped "Plant" object.
 * @param customer A pointer to the Customer to be associated with the plant.
 */
void Arrangement::addCust(Customer *customer)
{
	plant->addCust(customer);
}
