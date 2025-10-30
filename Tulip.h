#ifndef TULIP_H
#define TULIP_H

#include "Plant.h"

/** @class Tulip
 * @brief A class representing a Tulip plant, derived from the Plant base class.
 * 
 * The Tulip class implements specific attributes and behaviors for Tulip plants,
 * including cloning functionality and printing details.
 */

class Tulip : public Plant {
public:
  /** @fn Tulip::Tulip()
   * @brief Constructor for the Tulip class.
   */
  Tulip();
  /** @fn std::string Tulip::getName()
   * @brief Returns the name of the plant.
   * @return A string representing the name of the plant.
   */
  std::string getName();
  /** @fn Tulip Tulip::*clone()
   * @brief Creates a clone of the Tulip object.
   */
  Tulip *clone();
  /** @fn void Tulip::print()
   * @brief Prints the details of the Tulip plant.
   */
  void print() override;

protected:
  /** @fn Tulip::Tulip(Tulip &toCopy)
   * @brief Copy constructor for the Tulip class.
   * @param toCopy A reference to the Tulip object to be copied.
   */
  Tulip(Tulip &toCopy);
};

#endif
