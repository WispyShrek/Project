#ifndef COLLECTION_H
#define COLLECTION_H
#include "Iterator.h"
template <typename T>

class Collection {
public:
	virtual Iterator* CreateIterator() = 0;
	virtual void addItem(T item) = 0;
	virtual void removeItem(T item) = 0;
	virtual bool isEmpty() = 0;
	virtual T getCurrItem() = 0;
};

#endif
