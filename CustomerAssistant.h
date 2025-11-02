#ifndef CUSTOMERASSISTANT_H
#define CUSTOMERASSISTANT_H
#include <iostream> //remove
#include "Customer.h"
#include "Staff.h"

/** @class CustomerAssistant
 * @brief A class representing a customer assistant staff member in the nursery.
 * 
 * The CustomerAssistant class is responsible for assisting customers,
 * notifying them of updates, and providing care services.
 */

class CustomerAssistant : public Staff {
private:
  vector<Customer*> custList;
public:
    /** @fn CustomerAssistant::CustomerAssistant()
     * @brief Constructor for CustomerAssistant class.
     */
    CustomerAssistant();
    /** @fn void CustomerAssistant::care()
     * @brief Implements care behavior for the customer assistant.
     */ 
    void care() override;
    /** @fn void CustomerAssistant::update()
     * @brief Updates the customer assistant's state.
     */
    void update() override;
    /** @fn void CustomerAssistant::notify(Customer* customer)
     * @brief Notifies the customer assistant about a customer.
     * @param customer Pointer to the Customer object to notify about.
     */
    bool notify(Customer* customer, Plant* plant) override;
    /** @fn CustomerAssistant::~CustomerAssistant()
     * @brief Destructor for CustomerAssistant class.
     */
   ~CustomerAssistant();

};

#endif
