#ifndef INVENTORY_H
#define INVENTORY_H

#include "Collection.h"

template <typename T>

class Inventory : Collection{

public:
	void addItem(T item);
	Iterator* CreateIterator();
	T getCurrItem();
	bool isEmpty();
	void removeItem(T item);
};

#endif
