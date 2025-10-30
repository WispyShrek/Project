#include "PartialSunCare.h"

/**
 * @brief Applies the specific care routine for plants that require partial sun.
 *
 * This is a concrete implementation of the `applyCare` method from the
 * `CareStrategy` base class, as part of the Strategy design pattern. It defines
 * the algorithm for caring for plants in partial sun conditions.
 */
void PartialSunCare::applyCare() {
	std::cout << "apply partial sun and shade care routine"; 
}
