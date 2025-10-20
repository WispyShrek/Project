#ifndef STAFF_H
#define STAFF_H

#include "SalesFloor.h"
#include "Customer.h"

class Staff : SalesFloor{
public:
	Customer* custList;
	virtual void care() = 0;
	virtual void notify(Customer* customer) = 0;
	virtual void update() = 0;
};

#endif
