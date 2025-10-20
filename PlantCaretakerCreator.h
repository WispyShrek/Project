#ifndef PLANTCARETAKERCREATOR_H
#define PLANTCARETAKERCREATOR_H
#include "StaffCreator.h"
#include "Staff.h"

class PlantCaretakerCreator : StaffCreator{
public:
	PlantCaretakerCreator();
	Staff* createStaff();
};

#endif
