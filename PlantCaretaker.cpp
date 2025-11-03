#include "PlantCaretaker.h"
#include "Garden.h"
/// @brief Default constructor for PlantCaretaker.
/// Initializes the care queue and customer list.
PlantCaretaker::PlantCaretaker() {
  careQueue = {};
  custList = {};
}
/// @brief Destructor for PlantCaretaker.
/// Clears the care queue and deletes all customers in the list.
PlantCaretaker::~PlantCaretaker() {
  while (!careQueue.empty()) {
    careQueue.pop();
  }
  for (int i = 0; i < int(custList.size()); i++) {
    delete custList[i];
    custList[i] = NULL;
  }
}
/// @brief Applies care to the next garden in the queue.
/// Pops the front garden from the queue and calls its applyCare method.
void PlantCaretaker::care() {
  if (!careQueue.empty()) {
    Garden *toCareFor = careQueue.front();
    careQueue.pop();
    toCareFor->applyCare();
  }
}
/// @brief Adds a garden to the care queue.
/// @param subjectOfCare Pointer to the Garden object needing care.
void PlantCaretaker::update(Garden *subjectOfCare) {
  this->careQueue.push(subjectOfCare);
}