#ifndef STAFFCREATOR_H
#define STAFFCREATOR_H

#include "Staff.h"

/** @class StaffCreator
 * @brief An abstract factory class for creating Staff objects.
 * 
 * The StaffCreator class defines the interface for creating different types of
 * staff members in the nursery.
 */

class StaffCreator {
private:
	Staff* staff;

protected:
	virtual Staff* createStaff() = 0;

public:
	/** @fn StaffCreator::StaffCreator()
	 * @brief Constructor for StaffCreator class.
	 */
	StaffCreator(); 
	/** @fn Staff* StaffCreator::getStaff()
	 * @brief Creates and returns a Staff object.
	 * @return Pointer to the created Staff object.
	 */
	~StaffCreator();
};

#endif
