#include "PlantCaretaker.h"
#include "Garden.h"

PlantCaretaker::PlantCaretaker() {
  careQueue = {};
  custList = {};
}
PlantCaretaker::~PlantCaretaker() {
  while (!careQueue.empty()) {
    careQueue.pop();
  }
  for (int i = 0; i < int(custList.size()); i++) {
    delete custList[i];
    custList[i] = NULL;
  }
}
void PlantCaretaker::care() {
  if (!careQueue.empty()) {
    Garden *toCareFor = careQueue.front();
    careQueue.pop();
    toCareFor->applyCare();
  }
}

const std::queue<Garden *> &PlantCaretaker::getCareQueue() {
  return this->careQueue;
}

void PlantCaretaker::update(Garden *subjectOfCare) {
  this->careQueue.push(subjectOfCare);
}

#ifdef ENABLE_DOCTESTS
#include "Sunny.h"
#include "doctest.h"
TEST_CASE("Testing update function") {
  Garden *g = new Sunny();
  PlantCaretaker *carer = new PlantCaretaker();
  g->attach(carer);
  g->notify();
  CHECK(carer->getCareQueue().size() == 1);
  CHECK(carer->getCareQueue().front() == g);
}
TEST_CASE("Testing care function") {
  Garden *g = new Sunny();
  Garden *g2 = new Sunny();
  PlantCaretaker *carer = new PlantCaretaker();
  SUBCASE("applying care when the careQueue has items") {
    g->attach(carer);
    g2->attach(carer);
    g->notify();
    CHECK(carer->getCareQueue().front() == g);
    g2->notify();
    CHECK(carer->getCareQueue().back() == g2);
    CHECK(carer->getCareQueue().size() == 2);
    carer->care();
    CHECK(carer->getCareQueue().front() == g2);
    CHECK(carer->getCareQueue().size() == 1);
    carer->care();
    CHECK(carer->getCareQueue().size() == 0);
  }
  SUBCASE("attempting to call care when the careQueue is empty") {
    carer->care();
  }
}
#endif
