#ifndef SALESFLOOR_H
#define SALESFLOOR_H

class Customer;

class SalesFloor {
public:
  virtual void notify(Customer *customer) = 0;
};

#endif
