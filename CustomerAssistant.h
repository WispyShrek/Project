#ifndef CUSTOMERASSISTANT_H
#define CUSTOMERASSISTANT_H
#include <iostream> //remove
#include "Customer.h"
#include "Staff.h"

class CustomerAssistant : public Staff {
private:
  vector<Customer*> custList;
public:
    CustomerAssistant();
    void care() override;
    void update() override;
    void notify(Customer* customer) override; 
   ~CustomerAssistant();

};

#endif
