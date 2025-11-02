#include "PartialSun.h"
#include "Dying.h"

PartialSun::PartialSun() {
}

void PartialSun::applyRays() {
  Iterator<Plant *> *plants = CreateIterator();
  plants->first();
  while (!plants->isDone()) {
    if (plants->currItem() != nullptr) {
      if (plants->currItem()->getStrategy() == "PartialSun") {
        plants->currItem()->setState(new Dying());
      }
    }
    plants->next();
  }
}
