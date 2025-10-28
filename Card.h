#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "PaymentStrategy.h"

class Card : public PaymentStrategy {
public:
  void pay();
};

#endif
