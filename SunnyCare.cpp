/**
 * @file SunnyCare.cpp
 * @brief Implementation of the SunnyCare class.
 */
#include "SunnyCare.h"
#include <iostream>

/**
 * @brief Constructor for the SunnyCare class.
 *
 * Initializes the care strategy and sets its name to "Sunny".
 */
SunnyCare::SunnyCare() { this->strategyName = "Sunny"; }

/**
 * @brief Applies the care routine for sunny conditions.
 *
 * This method implements the specific care logic for plants that prefer
 * full sun, which involves printing a descriptive message to the console.
 */
void SunnyCare::applyCare() {
	std::cout << "Giving the plant full sunlight and regular watering"; 
}
