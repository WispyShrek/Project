#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "Staff.h"

class Garden : Collection<Garden*>{
public:
	Staff* staffList;
	virtual void Print() = 0;
	void addItem(Garden* item);
	Iterator* CreateIterator();
	Garden* getCurrItem();
	bool isEmpty();
	//void removeItem(T item);
	void TemplateMethod();
	virtual void applyRays() = 0;
	void attach(Staff* staff);
	void detach(Staff* staff);
	void notify();
};

#endif
