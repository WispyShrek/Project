#ifndef FUSSYCUST_H
#define FUSSYCUST_H
#include "Customer.h"
#include "SalesFloor.h"
#include <string>
#include <vector>
/// @brief Represents a fussy customer with specific preferences and a payment
/// strategy. Inherits from the abstract Customer class.
class FussyCust : public Customer {
private:
  /// @brief Pointer to the customer's chosen payment strategy.
  PaymentStrategy *paymentStrategy;

public:
  /// @brief Default constructor.
  FussyCust();
  /// @brief Parameterized constructor.
  /// @param name Name of the customer.
  /// @param salesFloor Pointer to the SalesFloor object.
  /// @param timeAvailable Time available for shopping.
  /// @param paymentStrategy Pointer to the PaymentStrategy object.
  /// @param preferredPlants Vector of preferred Plant pointers.
  FussyCust(std::string name, SalesFloor *salesFloor, double timeAvailable,
            PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants);
  /// @brief Destructor.
  /// Cleans up resources used by the customer.
  ~FussyCust();
  /// @brief Executes the customer's payment strategy.
  void pay();
  /// @brief Returns a voice line specific to FussyCust.
  /// @return A string representing the customer's voice line.
  string voiceLine() override;
  /// @brief Gets the customer's payment strategy.
  /// @return Pointer to the PaymentStrategy object.
  PaymentStrategy *getPaymentStrategy() const;
  /// @brief Sets the customer's payment strategy.
  /// @param strategy Pointer to the new PaymentStrategy object.
  void setPaymentStrategy(PaymentStrategy *strategy);
  /// @brief Enquires about preferred plants from the sales floor.
  /// If a preferred plant is available, adds it to the cart and removes it from
  /// preferences.
  /// @param salesFloor Pointer to the SalesFloor object.
  string enquirePlants(SalesFloor *salesFloor) override;
};
#endif
