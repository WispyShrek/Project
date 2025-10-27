#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Plant.h"
#include "SalesFloor.h"
using namespace std;

class Customer{
private:
	vector<Plant *> cart;
	SalesFloor* salesFloor;
	std::string name;

public:
	void changed();
	virtual void get() = 0;
	virtual void set() = 0;
};

#endif
