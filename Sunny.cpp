#include "Sunny.h"
#include "Dying.h"

Sunny::Sunny() {
  // TODO - implement Sunny::Sunny
}

void Sunny::applyRays() {
  // TODO - implement Sunny::applyRays
  Iterator<Plant *> *plants = CreateIterator();
  plants->first();
  while (!plants->isDone()) {
    if (plants->currItem() != nullptr) {
      if (plants->currItem()->getStrategy() != "Sunny") {
        plants->currItem()->setState(new Dying());
      }
    }
    plants->next();
  }
}
