#ifndef EFT_H
#define EFT_H
#include <iostream>
#include "PaymentStrategy.h"

/**
 * @class EFT
 * @brief A concrete payment strategy for Electronic Funds Transfer (EFT).
 *
 * This class inherits from PaymentStrategy and implements the `pay` method
 * to handle payments made via EFT.
 */
class EFT : public PaymentStrategy {
public:
  /**
   * @brief Executes the payment process for EFT.
   *
   * Overrides the pure virtual function in PaymentStrategy to provide
   * the specific logic for an EFT payment, which in this case is printing
   * a message to the console.
   */
  void pay();
};

#endif
