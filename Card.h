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
  /**
   * @brief Executes the payment process for a card.
   *
   * Overrides the pure virtual function in PaymentStrategy to provide
   * the specific logic for a card payment, which in this case is printing
   * a message to the console.
   */
  void pay();
};

#endif 
