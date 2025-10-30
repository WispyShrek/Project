#include "ShadyCare.h"

/**
 * @brief Applies the specific care routine for plants that require shade.
 *
 * This is a concrete implementation of the `applyCare` method from the
 * `CareStrategy` base class, as part of the Strategy design pattern. It defines
 * the algorithm for caring for plants in shady conditions.
 */
void ShadyCare::applyCare() {
	std::cout << "Giving the plant a few hours of sun daily"; 
}
