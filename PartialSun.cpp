#include "PartialSun.h"
#include "Dying.h"

PartialSun::PartialSun() {
}

void PartialSun::applyRays() {
  Iterator<Plant *> *plants = CreateIterator();
  plants->first();
  while (!plants->isDone()) {
    if (plants->currItem() != nullptr) {
      double roll = chance(gen);
      if (roll <= 0.2) {
        if (plants->currItem()->getStrategy() != "PartialSun") {
          if (plants->currItem()->getState() == "Dying") {
            plants->currItem()->setState(new Dead());
          } else if (plants->currItem()->getState() != "Dead") {
            Caretaker *caretaker = new Caretaker();
            caretaker->setPlantMemento(
                plants->currItem()->createPlantMemento());
            plants->currItem()->setState(new Dying(caretaker));
          }
          changed = true;
        } else {
          plants->currItem()->nextState();
        }
      } else if (roll <= 0.3) {
        plants->currItem()->nextState();
      }
    }
    plants->next();
  }
}
