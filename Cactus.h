#ifndef CACTUS_H
#define CACTUS_H
#include "AridCare.h"
#include "Plant.h"

/** @class Cactus
 * @brief A class representing a Cactus plant, derived from the Plant base
 * class.
 *
 * The Cactus class implements specific attributes and behaviors for Cactus
 * plants, including cloning functionality and printing details.
 */

class Cactus : public Plant {
public:
  /** @fn Cactus::Cactus()
   * @brief Constructor for the Cactus class.
   */
  Cactus();
  /** @fn std::string Cactus::getName()
   * @brief Returns the name of the plant.
   * @return A string representing the name of the plant.
   */
  std::string getName() override;
  /** @fn Cactus Cactus::*clone()
   * @brief Creates a clone of the Cactus object.
   */
  Cactus *clone() override;
  /** @fn std::string Cactus::print()
   * @brief Returns the details of the Cactus plant.
   * @return A string representation of the plant.
   */
  std::string print() override;
  /** @fn double Cactus::getPrice()
   * @brief Returns the price of the Cactus plant.
   * @return A double representing the price of the plant.
   */
  double getPrice() override;

protected:
  /** @fn Cactus::Cactus(Cactus &toCopy)
   * @brief Copy constructor for the Cactus class.
   * @param toCopy A reference to the Cactus object to be copied.
   */
  Cactus(Cactus &toCopy);
};

#endif
