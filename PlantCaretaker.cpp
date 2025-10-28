#include "PlantCaretaker.h"
#include "Garden.h"

PlantCaretaker::PlantCaretaker() {
  // TODO - implement PlantCaretaker::PlantCaretaker
}

void PlantCaretaker::care() {
  if (!careQueue.empty()) {
    Garden *toCareFor = careQueue.front();
    toCareFor->applyCare();
  }
}

void PlantCaretaker::update(Garden *subjectOfCare) {
  this->careQueue.push(subjectOfCare);
}

