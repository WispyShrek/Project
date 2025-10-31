#ifndef PLANTCARETAKERCREATOR_H
#define PLANTCARETAKERCREATOR_H
#include "Staff.h"
#include "StaffCreator.h"

/** @class PlantCaretakerCreator
 * @brief A factory class for creating PlantCaretaker staff members.
 * 
 * The PlantCaretakerCreator class inherits from StaffCreator and implements
 * the factory method to create PlantCaretaker objects.
 */

class PlantCaretakerCreator : public StaffCreator {
public:
  /** @fn PlantCaretakerCreator::PlantCaretakerCreator()
   * @brief Constructor for PlantCaretakerCreator class.
   */
  PlantCaretakerCreator();
  /** @fn Staff* PlantCaretakerCreator::createStaff()
   * @brief Creates and returns a new PlantCaretaker staff member.
   * @return Pointer to the newly created PlantCaretaker object.
   */
  Staff *createStaff();
};

#endif
