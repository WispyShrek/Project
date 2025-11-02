/**
 * @file CustomerAssistant.cpp
 * @brief Implementation of the CustomerAssistant class.
 */
#include "CustomerAssistant.h"
#include <iostream>

/**
 * @brief Default constructor for the CustomerAssistant.
 * Initializes an empty list of customers.
 */
CustomerAssistant::CustomerAssistant()
{
    custList = {};
}

/**
 * @brief Destructor for the CustomerAssistant.
 * Cleans up memory by deleting all Customer objects in the `custList`.
 */
CustomerAssistant::~CustomerAssistant() {
    for(int i=0; i<int(custList.size()); i++) {
        delete custList[i];
        custList[i] = NULL;
    }
} 

/**
 * @brief Implements the care behavior for a CustomerAssistant.
 * This is a placeholder implementation as assistants do not directly care for plants.
 * It prints a message indicating this role.
 */
void CustomerAssistant::care()
{
    cout << "CustomerAssistant: should not be doing anything with plants\n";
}

/**
 * @brief Notifies the assistant about a change in a customer's state.
 * This method is likely called by an observed subject (like SalesFloor)
 * to inform the assistant of an update, such as a change in a customer's cart.
 * @param customer A pointer to the customer who has been updated.
 */
void CustomerAssistant::notify(Customer *customer)
{
    
    cout << "CustomerAssistant: notifying customer. Customer cart has changed:\n" << customer->cartToString() << "\n";
}

/**
 * @brief Receives a generic update notification.
 * This method is likely part of the Observer pattern, called when the observed
 * subject changes. It prints a confirmation message.
 */
void CustomerAssistant::update()
{

    cout << "CustomerAssistant: update() received from floor/garden\n";
}


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("CustomerAssistant: Test CustomerAssistant class") {
    SalesFloor* floor = nullptr;
    CustomerAssistant* assistant = new CustomerAssistant();

    assistant->care();

    class MockCustomer : public Customer {
    public:
        MockCustomer() : Customer("TestCustomer", nullptr) {}
        void get() override {}
        void set() override {}
    };

    MockCustomer* mockCustomer = new MockCustomer();
    assistant->notify(mockCustomer);

    // Test update method
    assistant->update();

    delete mockCustomer;
    delete assistant;
}
TEST_CASE("CustomerAssistant: Test Destructor") {
    CustomerAssistant* assistant = new CustomerAssistant();
    delete assistant; // Ensure no memory leaks occur
}
#endif
