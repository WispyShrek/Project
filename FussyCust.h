#ifndef FUSSYCUST_H
#define FUSSYCUST_H
#include "Customer.h"

class FussyCust : public Customer {
private:
  vector<Plant *> preferredPlants; // vector to hold preferred plants
  PaymentStrategy *paymentStrategy;

public:
  FussyCust();
  FussyCust(std::string name, SalesFloor *salesFloor,double timeAvailable, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants);
  ~FussyCust();
  void pay();
  string voiceLine() override;
  PaymentStrategy *getPaymentStrategy() const { return paymentStrategy; }
  void setPaymentStrategy(PaymentStrategy *strategy) { paymentStrategy = strategy; }
  void enquirePlants(SalesFloor *salesFloor) override;
};
#endif
