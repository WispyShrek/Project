#ifndef EFT_H
#define EFT_H
#include <iostream>
#include "PaymentStrategy.h"

class EFT : public PaymentStrategy {
public:
  void pay();
};

#endif
