#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "Plant.h"
#include "Arrangement.h"
#include "Giftwrapping.h"
#include "DecorativePot.h"
#include "Customisation.h"
#include "PaymentStrategy.h"
#include "SalesFloor.h"
using namespace std;

class Customer
{
private: // attributes
	vector<Plant *> cart;
	SalesFloor *salesFloor;
	string name;
	double timeAvailable; // time available in minutes

public:
	Customer();
	Customer(std::string name, SalesFloor *salesFloor, double timeAvailable);
	virtual ~Customer();
	virtual string voiceLine() = 0;
	string getTimeLine();
	void addDecoration(string type, Plant *plant);
	void addToCart(Plant *plant);
	void removeFromCart(Plant *plant);
	string cartToString();
	virtual void enquirePlants(SalesFloor *salesFloor)=0;
};

#endif
