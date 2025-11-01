#ifndef PAYMENTSTARTEGY_H
#define PAYMENTSTARTEGY_H

class PaymentStrategy
{

public:
	virtual ~PaymentStrategy() = default;
	virtual void pay() = 0;
};

#endif
