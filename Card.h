#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "PaymentStrategy.h"

class Card : public PaymentStrategy {
public:
  Card(){}
  ~Card(){}
  void pay();
};

#endif
