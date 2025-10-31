#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

/**
 * @class PaymentStrategy
 * @brief An abstract base class for different payment strategies.
 *
 * This class defines the interface for various payment methods as part of the
 * Strategy design pattern. Concrete payment strategies must inherit from this
 * class and implement the `pay` method.
 */
class PaymentStrategy {


public:
	/**
	 * @brief Virtual destructor.
	 * Ensures that destructors of derived classes are called correctly.
	 */
	virtual ~PaymentStrategy() = default;
	/**
	 * @fn virtual void PaymentStrategy::pay() = 0
	 * @brief Executes the payment process for a specific strategy.
	 *
	 * This is a pure virtual function that must be implemented by concrete
	 * subclasses to define the specific payment logic (e.g., cash, EFT).
	 */
	virtual void pay() = 0;
};

#endif // PAYMENTSTRATEGY_H
