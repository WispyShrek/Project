#ifndef SALESFLOOR_H
#define SALESFLOOR_H
#include "Customer.h"
#include "Inventory.h"
#include <vector>
class Customer;

class SalesFloor{
public:
  virtual void notify(Customer *customer) = 0;

private:
  std::vector<Inventory*> inventories;
};

#endif
