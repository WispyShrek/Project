/**
 * @file DecorativePot.cpp
 * @brief Implementation of the DecorativePot concrete decorator.
 */
#include "DecorativePot.h"

/**
 * @brief Increases the price of the wrapped plant by a fixed amount for the decorative pot.
 *
 * This method is an implementation of the decorator functionality. It calls the
 * `increasePrice` method on the wrapped `Plant` object, adding the cost
 * specific to this decorative pot (200).
 */
void DecorativePot::increasePrice()
{
	plant->increasePrice(200);
}

/**
 * @brief Delegates the `addCust` call to the wrapped `Plant` object.
 * @param customer A pointer to the Customer to be associated with the plant.
 */
void DecorativePot::addCust(Customer *customer)
{
	plant->addCust(customer);
}
