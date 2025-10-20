#ifndef CUSTOMERASSISTANTCREATOR_H
#define CUSTOMERASSISTANTCREATOR_H
#include "StaffCreator.h"
#include "CustomerAssistant.h"

class CustomerAssistantCreator : StaffCreator {
public:
	CustomerAssistantCreator();
	Staff* createStaff();
};

#endif
