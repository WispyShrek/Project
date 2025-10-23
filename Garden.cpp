#include "Garden.h"
#include <algorithm>

void Garden::addItem(Garden *item) {}

Iterator<Garden *> *Garden::CreateIterator() { return nullptr; }

Garden *Garden::getCurrItem() {}

bool Garden::isEmpty() { return false; }

void Garden::removeItem(Garden *item) {}

void Garden::TemplateMethod() {}

void Garden::applyCare() {}

void Garden::attach(PlantCaretaker *staff) { this->staffList.push_back(staff); }

void Garden::detach(PlantCaretaker *staff) {
  this->staffList.erase(std::find(staffList.begin(), staffList.end(), staff));
}

void Garden::notify() {
  for (auto staff : staffList) {
    staff->update(this);
  }
}
