#ifndef PLANTCARETAKERCREATOR_H
#define PLANTCARETAKERCREATOR_H
#include "Staff.h"
#include "StaffCreator.h"

class PlantCaretakerCreator : public StaffCreator {
public:
  PlantCaretakerCreator();
  Staff *createStaff();
};

#endif
