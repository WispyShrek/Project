#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>
class Plant;

class PlantState {
public:
    virtual ~PlantState() {}  
    virtual void next(Plant *context) = 0;
    virtual void print() = 0;
};

#endif
