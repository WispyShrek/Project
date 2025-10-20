#ifndef GARDENITERATOR_H
#define GARDENITERATOR_H
#include "Iterator.h"
#include "Garden.h"

class GardenIterator : Iterator{
public:
	Garden* currItem();
	void first();
	bool isDone();
	void next();
	void prev();
};

#endif
