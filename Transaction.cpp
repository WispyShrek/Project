#include "Transaction.h"
#include "PaymentStrategy.h"

void Transaction::pay() {
    if (paymentStrategy) {//ensure strategy is set
        paymentStrategy->pay(); 
    } else {
        std::cout << "No payment strategy set :(" << std::endl;
    }
}

void Transaction::setPaymentStrategy(PaymentStrategy* strategy) {
    this->paymentStrategy = strategy;
}
