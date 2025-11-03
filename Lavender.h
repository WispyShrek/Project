#ifndef LAVENDER_H
#define LAVENDER_H
#include "PartialSunCare.h"
#include "Plant.h"

/** @class Lavender
 * @brief A class representing a Lavender plant, derived from the Plant base
 * class.
 *
 * The Lavender class implements specific attributes and behaviors for Lavender
 * plants, including cloning functionality and printing details.
 */

class Lavender : public Plant {
public:
  /** @fn Lavender::Lavender()
   * @brief Constructor for the Lavender class.
   */
  Lavender();
  /** @fn std::string Lavender::getName()
   * @brief Returns the name of the plant.
   * @return A string representing the name of the plant.
   */
  std::string getName() override;
  /** @fn Lavender Lavender::*clone()
   * @brief Creates a clone of the Lavender object.
   */
  Lavender *clone() override;
  /** @fn std::string Lavender::print()
   * @brief Returns the details of the Lavender plant.
   * @return A string representation of the plant.
   */
  std::string print() override;
  /** @fn double Lavender::getPrice()
   * @brief Returns the price of the Lavender plant.
   * @return A double representing the price of the plant.
   */
  double getPrice() override;

protected:
  /** @fn Lavender::Lavender(Lavender &toCopy)
   * @brief Copy constructor for the Lavender class.
   * @param toCopy A reference to the Lavender object to be copied.
   */
  Lavender(Lavender &toCopy);
};

#endif
