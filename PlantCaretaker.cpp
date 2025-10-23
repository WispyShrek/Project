#include "PlantCaretaker.h"
#include "Garden.h"

PlantCaretaker::PlantCaretaker() {
  // TODO - implement PlantCaretaker::PlantCaretaker
  throw "Not yet implemented";
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
