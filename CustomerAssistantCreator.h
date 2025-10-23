#ifndef CUSTOMERASSISTANTCREATOR_H
#define CUSTOMERASSISTANTCREATOR_H
#include "CustomerAssistant.h"
#include "StaffCreator.h"

class CustomerAssistantCreator : public StaffCreator {
public:
  CustomerAssistantCreator();
  Staff *createStaff();
};

#endif
