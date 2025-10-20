#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "SalesFloor.h"

class Customer{
private:
	SalesFloor* salesFloor;
	std::string name;

public:
	void changed();
	virtual void get() = 0;
	virtual void set() = 0;
};

#endif
