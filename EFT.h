#ifndef EFT_H
#define EFT_H
#include "PaymentStartegy.h"

class EFT : public PaymentStartegy {
public:
  void pay();
};

#endif
