#ifndef CUSTOMERASSISTANTCREATOR_H
#define CUSTOMERASSISTANTCREATOR_H
#include "CustomerAssistant.h"
#include "StaffCreator.h"

/** @class CustomerAssistantCreator
 * @brief A factory class for creating CustomerAssistant staff members.
 * 
 * The CustomerAssistantCreator class inherits from StaffCreator and implements
 * the factory method to create CustomerAssistant objects.
 */

class CustomerAssistantCreator : public StaffCreator {
public:
  /** @fn CustomerAssistantCreator::CustomerAssistantCreator()
   * @brief Constructor for CustomerAssistantCreator class.
   */
  CustomerAssistantCreator();
  /** @fn Staff* CustomerAssistantCreator::createStaff()
   * @brief Creates and returns a new CustomerAssistant staff member.
   * @return Pointer to the newly created CustomerAssistant object.
   */
  Staff *createStaff();
};

#endif
