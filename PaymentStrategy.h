#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

class PaymentStrategy {

/**
 * @brief Concrete implementation of strategy method pay() with Cash
 */
public:
	virtual void pay() = 0;
};

#endif // PAYMENTSTRATEGY_H
