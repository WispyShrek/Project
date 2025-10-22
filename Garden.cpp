#include "Garden.h"
#include <algorithm>

template <typename T> void Garden<T>::addItem(Garden *item) {}

template <typename T> Iterator *Garden<T>::CreateIterator() { return nullptr; }

// template <typename T>
// Garden *Garden<T>::getCurrItem()
//{
//     return nullptr;
// }

template <typename T> bool Garden<T>::isEmpty() { return false; }

template <typename T> void Garden<T>::removeItem(T item) {}

void applyCare() {}

void Garden::attach(PlantCaretaker *staff) { this->staffList.push_back(staff); }

void Garden::detach(PlantCaretaker *staff) {
  this->staffList.erase(std::find(staffList.begin(), staffList.end(), staff));
}

void Garden::notify() {
  for (auto staff : staffList) {
    staff->update(this);
  }
}
