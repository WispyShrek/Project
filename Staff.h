#ifndef STAFF_H
#define STAFF_H
#include <vector>
#include "Customer.h"
#include "SalesFloor.h"

class Staff : public SalesFloor
{

public:
  virtual ~Staff();
  virtual void care() = 0;
  virtual void notify(Customer *customer) {};
  virtual void update() {};
};

#endif
