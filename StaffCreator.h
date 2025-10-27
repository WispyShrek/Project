#ifndef STAFFCREATOR_H
#define STAFFCREATOR_H

#include "Staff.h"

class StaffCreator {
private:
	Staff* staff;

protected:
	virtual Staff* createStaff() = 0;

public:
	StaffCreator(); 
	~StaffCreator();
};

#endif
