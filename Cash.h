#ifndef CASH_H
#define CASH_H
#include <iostream>
#include "PaymentStrategy.h"

class Cash : public PaymentStrategy {

public:
  Cash(){}
  ~Cash(){}
  void pay();
};

#endif
