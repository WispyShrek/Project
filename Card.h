/**
 * @file Card.h
 * @brief Definition of the Card class for card payments.
 */
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "PaymentStrategy.h"

/**
 * @class Card
 * @brief A concrete payment strategy for card payments.
 *
 * This class inherits from PaymentStrategy and implements the `pay` method
 * to handle payments made by credit or debit card.
 */
class Card : public PaymentStrategy {
public:
  Card(){}
  ~Card(){}
  void pay();
};

#endif 
