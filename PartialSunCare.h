/**
 * @file PartialSunCare.h
 * @brief Definition of the PartialSunCare class, a concrete care strategy.
 */
#ifndef PARTIALSUNCARE_H
#define PARTIALSUNCARE_H
#include <iostream>

#include "CareStrategy.h"

/**
 * @class PartialSunCare
 * @brief A concrete care strategy for plants that prefer partial sun conditions.
 *
 * This class inherits from CareStrategy and implements the `applyCare` method
 * to provide a specific care routine suitable for plants needing a mix of sun and shade.
 */
class PartialSunCare : public CareStrategy {
public:
  /**
   * @brief Constructor for the PartialSunCare class.
   * Sets the strategy name to "PartialSun".
   */
  PartialSunCare();
  /**
   * @brief Applies the care routine for partial sun conditions.
   * Overrides the pure virtual function in CareStrategy to define the specific
   * care logic, which involves printing a message to the console.
   */
  void applyCare() override;
};

#endif // PARTIALSUNCARE_H
