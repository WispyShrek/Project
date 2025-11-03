/**
 * @file Cash.h
 * @brief Definition of the Cash class for cash payments.
 */
#ifndef CASH_H
#define CASH_H
#include <iostream>
#include "PaymentStrategy.h"

/**
 * @class Cash
 * @brief A concrete payment strategy for cash payments.
 *
 * This class inherits from PaymentStrategy and implements the `pay` method
 * to handle payments made with cash.
 */
class Cash : public PaymentStrategy {

public:
  /**
   * @brief Executes the payment process for cash.
   *
   * Overrides the pure virtual function in PaymentStrategy to provide
   * the specific logic for a cash payment, which in this case is printing
   * a message to the console.
   */
  void pay();
};

#endif // CASH_H
