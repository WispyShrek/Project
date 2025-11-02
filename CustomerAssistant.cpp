#include "CustomerAssistant.h"
#include <iostream>

CustomerAssistant::CustomerAssistant() { custList = {}; }
CustomerAssistant::~CustomerAssistant() {
  for (int i = 0; i < int(custList.size()); i++) {
    delete custList[i];
    custList[i] = NULL;
  }
}
void CustomerAssistant::care() {
  cout << "CustomerAssistant: should not be doing anything with plants\n";
}
bool CustomerAssistant::notify(Customer *customer, Plant *plant) {
  return false;
}

void CustomerAssistant::update() {

  cout << "CustomerAssistant: update() received from floor/garden\n";
}

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
