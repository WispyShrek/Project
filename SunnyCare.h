/**
 * @file SunnyCare.h
 * @brief Definition of the SunnyCare class, a concrete care strategy.
 */
#ifndef SUNNYCARE_H
#define SUNNYCARE_H
#include <iostream>

#include "CareStrategy.h"

/**
 * @class SunnyCare
 * @brief A concrete care strategy for plants that prefer sunny conditions.
 *
 * This class inherits from CareStrategy and implements the `applyCare` method
 * to provide a specific care routine suitable for sun-loving plants.
 */
class SunnyCare : public CareStrategy {
public:
  /**
   * @brief Constructor for the SunnyCare class.
   * Sets the strategy name to "Sunny".
   */
  SunnyCare();
  /**
   * @brief Applies the care routine for sunny conditions.
   * Overrides the pure virtual function in CareStrategy to define the specific
   * care logic, which involves printing a message to the console.
   */
  void applyCare() override;
};

#endif 
