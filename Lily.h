#ifndef LILY_H
#define LILY_H

#include "Plant.h"
#include "PartialSunCare.h"

/** @class Lily
 * @brief A class representing a Lily plant, derived from the Plant base class.
 * 
 * The Lily class implements specific attributes and behaviors for Lily plants,
 * including cloning functionality and printing details.
 */

class Lily : public Plant {
private:
  double price;
public:
  /** @fn Lily::Lily()
   * @brief Constructor for the Lily class.
   */
  Lily();
  /** @fn std::string Lily::getName()
   * @brief Returns the name of the plant.
   * @return A string representing the name of the plant.
   */
  std::string getName();
  /** @fn Lily Lily::*clone()
   * @brief Creates a clone of the Lily object.
   */
  Lily *clone();
  /** @fn void Lily::print()
   * @brief Prints the details of the Lily plant.
   */
  void print() override;
  /** @fn void Lily::getPrice()
   * @brief Returns the price of the Lily plant.
   * @return A double representing the price of the plant.
   */
  double getPrice() override;

protected:
  /** @fn Lily::Lily(Lily &toCopy)
   * @brief Copy constructor for the Lily class.
   * @param toCopy A reference to the Lily object to be copied.
   */
  Lily(Lily &toCopy);

};

#endif
