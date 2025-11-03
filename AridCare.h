/**
 * @file AridCare.h
 * @brief Definition of the AridCare class, a concrete care strategy.
 */
#ifndef ARIDCARE_H
#define ARIDCARE_H
#include <iostream>

#include "CareStrategy.h"

/**
 * @class AridCare
 * @brief A concrete care strategy for plants that prefer arid conditions.
 *
 * This class inherits from CareStrategy and implements the `applyCare` method
 * to provide a specific care routine suitable for arid-loving plants.
 */
class AridCare : public CareStrategy {
public:
  /**
   * @brief Constructor for the AridCare class.
   * Sets the strategy name to "Arid".
   */
  AridCare();
  /**
   * @brief Applies the care routine for arid conditions.
   * Overrides the pure virtual function in CareStrategy to define the specific
   * care logic, which involves printing a message to the console.
   */
  void applyCare() override;
};

#endif 
