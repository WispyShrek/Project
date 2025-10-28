#ifndef NURSERY_H
#define NURSERY_H
#include "Garden.h"
#include "Staff.h"

class Nursery {

private:
  static Nursery *uniqueInstance;
  Garden *gardens;
  Staff *staff;

public:
  static Nursery *instance();

protected:
  Nursery();
  ~Nursery();
  Nursery(Nursery &in);
};

#endif
