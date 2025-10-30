#include "SunnyCare.h"
#include <iostream>

/**
 * @brief Applies the specific care routine for plants that require full sun.
 *
 * This is a concrete implementation of the `applyCare` method from the
 * `CareStrategy` base class, as part of the Strategy design pattern. It defines
 * the algorithm for caring for plants in sunny conditions.
 */
void SunnyCare::applyCare() {
	std::cout << "Giving the plant full sunlight and regular watering"; 
}
