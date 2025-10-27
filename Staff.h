#ifndef STAFF_H
#define STAFF_H
#include <vector>
#include "Customer.h"
#include "SalesFloor.h"

class Staff : public SalesFloor
{
private:
  vector<Customer *> custList;
public:
  virtual ~Staff() {
    for(int i = 0; i < custList.size(); i++) {
      delete custList[i];
      custList[i] = NULL;
    }
  }
  virtual void care() = 0;
  virtual void notify(Customer *customer) {};
  virtual void update() {};
};

#endif
