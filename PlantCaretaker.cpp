#include "PlantCaretaker.h"
#include "Garden.h"

PlantCaretaker::PlantCaretaker() {
  careQueue = {};
  custList={};
}
PlantCaretaker::~PlantCaretaker() {
  while (!careQueue.empty()) {
    careQueue.pop();
  }
  for(int i=0; i<custList.size(); i++) {
      delete custList[i];
      custList[i] = NULL;
  }
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
