#include "Garden.h"
#include "PlantCaretaker.h"
#include "Sunny.h"
#include <algorithm>

Garden::~Garden() {
  // Clean up all plants
  Iterator<Plant *> *iterator = CreateIterator();
  iterator->first();
  while (!iterator->isDone()) {
    delete iterator->currItem();
    iterator->setCurrItem(nullptr);
    iterator->next();
  }
}

bool Garden::addItem(Plant *item) {
  Iterator<Plant *> *iterator = CreateIterator();
  iterator->first();
  while (!iterator->isDone()) {
    if (iterator->currItem() == nullptr) {
      iterator->setCurrItem(item);
      return true;
    }
    iterator->next();
  }
  return false;
}

Iterator<Plant *> *Garden::CreateIterator() {
  return new GardenIterator(plants);
}

void Garden::removeItem(Plant *item) {
  Iterator<Plant *> *iterator = CreateIterator();
  iterator->first();
  while (!iterator->isDone()) {
    if (iterator->currItem() == item) {
      delete iterator->currItem();
      iterator->setCurrItem(nullptr);
      return;
    }
    iterator->next();
  }
  this->staffList.clear();
}

void Garden::applyCare() {}

const std::vector<PlantCaretaker *> &Garden::getStaff() {
  return this->staffList;
}

void Garden::attach(PlantCaretaker *staff) { this->staffList.push_back(staff); }

void Garden::detach(PlantCaretaker *staff) {
  this->staffList.erase(std::find(staffList.begin(), staffList.end(), staff));
}

void Garden::notify() {
  for (auto plantCaretaker : staffList) {
    plantCaretaker->update(this);
  }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"
TEST_CASE("Testing the observer attach and detach functionality") {
  Garden *g = new Sunny();
  PlantCaretaker *carer = new PlantCaretaker();
  g->attach(carer);
  SUBCASE("Attaching a caretaker adds them to the staffList") {
    CHECK(g->getStaff().size() == 1);
    CHECK(g->getStaff().back() == carer);
  }
  PlantCaretaker *dummy = new PlantCaretaker();
  PlantCaretaker *dummy2 = new PlantCaretaker();
  g->attach(new PlantCaretaker());
  g->attach(new PlantCaretaker());
  g->detach(carer);
  SUBCASE("Detaching a caretaker removes them from the staffList") {
    CHECK(g->getStaff().back() != carer);
  }
  PlantCaretaker *carer2 = new PlantCaretaker();
  SUBCASE("Removing a carer not in the list does nothing") {
    g->detach(carer2);
  }
  SUBCASE("Removing from an empty list does nothing") {
    g->detach(dummy);
    g->detach(dummy2);
    g->detach(dummy2);
  }
}
TEST_CASE("Testing observer notify functionality") {
  Garden *g = new Sunny();
  PlantCaretaker *carer = new PlantCaretaker();
  g->attach(carer);
  g->notify();
  CHECK(carer->getCareQueue().front() == g);
}
#endif
