#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Plant.h"
#include "PaymentStrategy.h"
#include "SalesFloor.h"
using namespace std;

class Customer{
private://attributes
	vector<Plant *> cart;
	SalesFloor* salesFloor;
	string name;

public:
	Customer();
	Customer(std::string name, SalesFloor* salesFloor);
	virtual ~Customer();
	virtual string voiceLine()=0;
	void addDecoration(Plant* plant);
	void addToCart(Plant* plant);
	void removeFromCart(Plant* plant);
	string cartToString();
	void enquirePlants(SalesFloor* salesFloor);
};

#endif
