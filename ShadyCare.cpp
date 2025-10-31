/**
 * @file ShadyCare.cpp
 * @brief Implementation of the ShadyCare class.
 */
#include "ShadyCare.h"

/**
 * @brief Constructor for the ShadyCare class.
 *
 * Initializes the care strategy and sets its name to "Shady".
 */
ShadyCare::ShadyCare() { this->strategyName = "Shady"; }

/**
 * @brief Applies the care routine for shady conditions.
 *
 * This method implements the specific care logic for plants that prefer
 * shade, which involves printing a descriptive message to the console.
 */
void ShadyCare::applyCare() {
	std::cout << "Giving the plant a few hours of sun daily"; 
}
