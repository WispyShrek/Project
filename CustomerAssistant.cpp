#include "CustomerAssistant.h"
#include <iostream>

/// @brief Default constructor for CustomerAssistant.
/// Initializes the customer list.
CustomerAssistant::CustomerAssistant() { custList = {}; }
/// @brief Destructor for CustomerAssistant.
/// Deletes all dynamically allocated Customer objects in the list.

CustomerAssistant::~CustomerAssistant() {
  for (int i = 0; i < int(custList.size()); i++) {
    delete custList[i];
    custList[i] = NULL;
  }
}
/// @brief Displays a message indicating that CustomerAssistant does not
/// handle plants.
void CustomerAssistant::care() {}
/// @brief Receives an update notification from the floor or garden.

/// @brief Notifies the assistant to remove a plant from inventory.
/// @param customer Pointer to the Customer initiating the notification.
/// @param plant Pointer to the Plant to be removed.
/// @return True if the plant was successfully removed from inventory.

bool CustomerAssistant::notify(Customer *customer, Plant *plant) {
  return this->inventory.removeItem(plant->getName());
}
/// @brief Receives an update notification from the floor or garden.
void CustomerAssistant::update() {}
/// @brief Unit test for basic functionality of CustomerAssistant.

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("CustomerAssistant: Test CustomerAssistant class") {
  SalesFloor *floor = nullptr;
  CustomerAssistant *assistant = new CustomerAssistant();

  assistant->care();

  // Test update method
  assistant->update();

  delete mockCustomer;
  delete assistant;
}
TEST_CASE("CustomerAssistant: Test Destructor") {
  CustomerAssistant *assistant = new CustomerAssistant();
  delete assistant; // Ensure no memory leaks occur
}
#endif
