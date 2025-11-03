#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"
#include "SunnyCare.h"

/** @class Rose
 * @brief A class representing a Rose plant, derived from the Plant base class.
 *
 * The Rose class implements specific attributes and behaviors for Rose plants,
 * including cloning functionality and printing details.
 */

class Rose : public Plant {
public:
  /** @fn Rose::Rose()
   * @brief Constructor for the Rose class.
   */
  Rose();
  /** @fn std::string Rose::getName()
   * @brief Returns the name of the plant.
   * @return A string representing the name of the plant.
   */
  std::string getName() override;
  /** @fn Rose Rose::*clone()
   * @brief Creates a clone of the Rose object.
   */
  Rose *clone() override;
  /** @fn std::string Rose::print()
   * @brief Returns the details of the Rose plant.
   * @return A string representing the Rose plant.
   */
  std::string print() override;
  /** @fn double Rose::getPrice()
   * @brief Returns the price of the Rose plant.
   * @return A double representing the price of the plant.
   */
  double getPrice() override;

protected:
  /** @fn Rose::Rose(Rose &toCopy)
   * @brief Copy constructor for the Rose class.
   * @param toCopy A reference to the Rose object to be copied.
   */
  Rose(Rose &toCopy);
};

#endif
