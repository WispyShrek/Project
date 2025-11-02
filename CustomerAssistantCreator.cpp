/**
 * @file CustomerAssistantCreator.cpp
 * @brief Implementation of the CustomerAssistantCreator class.
 */
#include "CustomerAssistantCreator.h"

/**
 * @brief Default constructor for the CustomerAssistantCreator.
 * This constructor is empty as there is no specific initialization needed for this factory.
 */
CustomerAssistantCreator::CustomerAssistantCreator() {}

/**
 * @brief Factory method to create a CustomerAssistant object.
 *
 * This method implements the factory pattern to instantiate and return a new
 * `CustomerAssistant` object, fulfilling the contract of the `StaffCreator` base class.
 * @return A pointer to a new Staff object, specifically a `CustomerAssistant`.
 */
Staff* CustomerAssistantCreator::createStaff() {
    return new CustomerAssistant();  
}
