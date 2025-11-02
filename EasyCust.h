#ifndef EASYCUST_H
#define EASYCUST_H
#include "Customer.h"

class EasyCust : public Customer
{
private:
  vector<Plant *> preferredPlants; // vector to hold preferred plants
  PaymentStrategy *paymentStrategy;

public:
  EasyCust();
  EasyCust(std::string name, SalesFloor *salesFloor,double timeAvailable, PaymentStrategy *paymentStrategy, vector<Plant *> preferredPlants);
  ~EasyCust();
  void pay();
  string voiceLine() override;
  PaymentStrategy *getPaymentStrategy() const { return paymentStrategy; }
  void setPaymentStrategy(PaymentStrategy *strategy) { paymentStrategy = strategy; }
  void enquirePlants(SalesFloor *salesFloor) override;
};

#endif
