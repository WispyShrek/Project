#ifndef CARD_H
#define CARD_H
#include "PaymentStartegy.h"

class Card : public PaymentStartegy {
public:
  void pay();
};

#endif
