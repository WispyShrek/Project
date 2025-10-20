#ifndef TRANSACTION_H
#define TRANSACTION_H

class PaymentStrategy;

class Transaction {
private:
	PaymentStrategy* paymentStrategy;
public:
	void pay();
};

#endif
