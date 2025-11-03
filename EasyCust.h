#ifndef EASYCUST_H
#define EASYCUST_H
#include "Customer.h"
/// @brief Represents an easygoing customer with predefined preferences and a payment strategy.
/// Inherits from the abstract Customer class.
class EasyCust : public Customer
{
private:
  /// @brief Vector holding the customer's preferred plants.
  vector<Plant *> preferredPlants;
  /// @brief Pointer to the customer's chosen payment strategy.
  PaymentStrategy *paymentStrategy;

public:
  /// @brief Default constructor.
  EasyCust();
  /// @brief Parameterized constructor.
  /// @param name Name of the customer.
  /// @param salesFloor Pointer to the SalesFloor object.
  /// @param timeAvailable Time available for shopping.
  /// @param paymentStrategy Pointer to the PaymentStrategy object.
  /// @param preferredPlants Vector of preferred Plant pointers.
  EasyCust(std::string name, SalesFloor *salesFloor, double timeAvailable, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants);
  /// @brief Destructor.
  /// Cleans up preferred plants and payment strategy.
  ~EasyCust();
  /// @brief Executes the customer's payment strategy.
  void pay();
  /// @brief Returns a voice line specific to EasyCust.
  /// @return A string representing the customer's voice line.
  string voiceLine() override;
  /// @brief Gets the customer's payment strategy.
  /// @return Pointer to the PaymentStrategy object.
  PaymentStrategy *getPaymentStrategy() const;
  /// @brief Sets the customer's payment strategy.
  /// @param strategy Pointer to the new PaymentStrategy object.
  void setPaymentStrategy(PaymentStrategy *strategy);
  /// @brief Enquires about preferred plants from the sales floor.
  /// @param salesFloor Pointer to the SalesFloor object.
  void enquirePlants(SalesFloor *salesFloor) override;
};

#endif