#ifndef PLANTSTATE_H
#define PLANTSTATE_H
class Plant;

class PlantState {
public:
    virtual ~PlantState() {}  
    virtual void next(Plant *context) = 0;
};

#endif
