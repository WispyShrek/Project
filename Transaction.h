#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class PaymentStrategy;


class Transaction {
private:
	PaymentStrategy* paymentStrategy;
public:
    Transaction() : paymentStrategy(nullptr) {}
    void setPaymentStrategy(PaymentStrategy* strategy);
    void pay();
};

#endif // TRANSACTION_H
