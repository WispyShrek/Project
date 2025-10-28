#ifndef CUSTOMERASSISTANT_H
#define CUSTOMERASSISTANT_H
#include <iostream> //remove
#include "Customer.h"
#include "Staff.h"

class CustomerAssistant : public Staff {
public:
  CustomerAssistant();
    void care() override;
    void update() override;
    void notify(Customer* customer) override; 
};

#endif
