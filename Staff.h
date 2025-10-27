#ifndef STAFF_H
#define STAFF_H

#include "Customer.h"
#include "SalesFloor.h"

class Staff : public SalesFloor {
public:
  Customer *custList = nullptr;
  virtual ~Staff() {}  
  virtual void care() = 0;
  virtual void notify(Customer *customer) = 0;
  virtual void update() = 0;
};

#endif
