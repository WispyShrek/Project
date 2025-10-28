#ifndef CASH_H
#define CASH_H
#include "PaymentStartegy.h"

class Cash : public PaymentStartegy {

public:
  void pay();
};

#endif
