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
	string name;

public:
	Customer();
	Customer(std::string name, SalesFloor* salesFloor);
	~Customer();
	void addToCart(Plant* plant);
	void removeFromCart(Plant* plant);
	string cartToString();
	void changed();
	virtual void get() = 0;
	virtual void set() = 0;
};

#endif
