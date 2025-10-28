#ifndef SALESFLOOR_H
#define SALESFLOOR_H
#include "Customer.h"
#include <vector>
class Customer;

class SalesFloor
{
public:
  virtual void notify(Customer *customer) = 0;
};

#endif
