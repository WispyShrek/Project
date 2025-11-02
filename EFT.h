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
  EFT(){}
  ~EFT(){}
  void pay();
};

#endif
