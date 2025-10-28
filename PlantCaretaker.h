#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H
#include <iostream>

#include "Staff.h"

class PlantCaretaker : public Staff {
public:
  PlantCaretaker();
    void care() override;
    void update() override;
    void notify(Customer* customer) override; 
};

#endif
