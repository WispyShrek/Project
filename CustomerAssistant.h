#ifndef CUSTOMERASSISTANT_H
#define CUSTOMERASSISTANT_H
#include "Customer.h"
#include "Staff.h"

class CustomerAssistant : public Staff {
private:
  vector<Customer*> custList;
public:
  CustomerAssistant();
  ~CustomerAssistant();
  void care();
  void notify(Customer *customer);
  void update() override; 
};

#endif
