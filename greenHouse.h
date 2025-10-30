#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "Garden.h"
#include "Collection.h"
#include "GardenIterator.h"
#include <vector>

class greenHouse : public Collection<Garden*> {
private:
	std::vector<Garden*> gardens;
public:
	void powerSystem();
	Iterator<Garden*> *CreateIterator();
    void addItem(Garden* item);
    void removeItem(Garden* item);
};

#endif
