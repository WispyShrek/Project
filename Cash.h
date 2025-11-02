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
  Cash(){}
  ~Cash(){}
  void pay();
};

#endif // CASH_H
