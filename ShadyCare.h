/**
 * @file ShadyCare.h
 * @brief Definition of the ShadyCare class, a concrete care strategy.
 */
#ifndef SHADYCARE_H
#define SHADYCARE_H
#include <iostream>

#include "CareStrategy.h"

/**
 * @class ShadyCare
 * @brief A concrete care strategy for plants that prefer shady conditions.
 *
 * This class inherits from CareStrategy and implements the `applyCare` method
 * to provide a specific care routine suitable for shade-loving plants.
 */
class ShadyCare : public CareStrategy {
public:
  /**
   * @brief Constructor for the ShadyCare class.
   * Sets the strategy name to "Shady".
   */
  ShadyCare();
  /**
   * @brief Applies the care routine for shady conditions.
   * Overrides the pure virtual function in CareStrategy to define the specific
   * care logic, which involves printing a message to the console.
   */
  void applyCare() override;
};

#endif
