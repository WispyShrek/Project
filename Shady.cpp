#include "Shady.h"
#include "Dying.h"

Shady::Shady() {
  // TODO - implement Shady::Shady
}

void Shady::applyRays() {
  // TODO - implement Shady::applyRays
  Iterator<Plant *> *plants = CreateIterator();
  plants->first();
  while (!plants->isDone()) {
    if (plants->currItem() != nullptr) {
      if (plants->currItem()->getStrategy() == "Shady") {
        plants->currItem()->setState(new Dying());
      }
    }
    plants->next();
  }
}
