#ifndef CUSTOMERASSISTANT_H
#define CUSTOMERASSISTANT_H
#include "Staff.h"
#include "Customer.h"

class CustomerAssistant : Staff {
public:
	CustomerAssistant();
	void care();
	void notify(Customer* customer);
};

#endif
