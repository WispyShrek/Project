/**
 * @file EFT.cpp
 * @brief Implementation of the EFT class.
 */
#include "EFT.h"

/**
 * @brief Executes the payment process for EFT.
 *
 * This method implements the payment logic for an Electronic Funds Transfer.
 * It prints a message to the standard output to signify that the payment
 * is being processed via EFT.
 */
std::string EFT::pay() { return "Paying with EFT"; }

#ifdef ENABLE_DOCTESTS
#include "Card.h"
#include "Cash.h"
#include "doctest.h"
#include <sstream>

TEST_SUITE("Payment Strategies") {
  TEST_CASE("EFT payment strategy prints correct message") {
    EFT eft_payment;
    std::string result = eft_payment.pay();
    CHECK(result == "Paying with EFT");
  }

  TEST_CASE("Card payment strategy prints correct message") {
    Card card_payment;
    std::string result = card_payment.pay();
    CHECK(result == "Paying with card");
  }

  TEST_CASE("Cash payment strategy prints correct message") {
    Cash cash_payment;
    std::string result = cash_payment.pay();
    CHECK(result == "Pay with cash");
  }
}
#endif
