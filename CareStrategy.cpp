/**
 * @file CareStrategy.cpp
 * @brief Implementation of the CareStrategy abstract base class.
 */
#include "CareStrategy.h"

/**
 * @brief Default constructor for the CareStrategy class.
 *
 * This constructor is empty as the base class has no specific initialization
 * logic to perform. Concrete strategies are responsible for setting the `strategyName`.
 */
CareStrategy::CareStrategy() {
}

/**
 * @brief Gets the name of the concrete strategy.
 * @return A string containing the value of the `strategyName` member.
 */
std::string CareStrategy::getStrategyName() { return this->strategyName; }

/**
 * @brief Virtual destructor for the CareStrategy class.
 *
 * The body is empty, but its presence as a virtual destructor is crucial
 * to ensure that derived class destructors are called correctly, preventing
 * resource leaks when deleting a concrete strategy through a base class pointer.
 */
CareStrategy::~CareStrategy() {}
