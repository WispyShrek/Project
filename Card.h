/**
 * @file Card.h
 * @brief Definition of the Card class for card payments.
 */
#ifndef CARD_H
#define CARD_H
#include "PaymentStrategy.h"
#include <iostream>

/**
 * @class Card
 * @brief A concrete payment strategy for card payments.
 *
 * This class inherits from PaymentStrategy and implements the `pay` method
 * to handle payments made by credit or debit card.
 */
class Card : public PaymentStrategy {
public:
  Card() {}
  ~Card() {}
  std::string pay();
};

#endif
