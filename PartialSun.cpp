#include "PartialSun.h"
#include "Dead.h"
#include "Dying.h"
#include <random>

PartialSun::PartialSun() {
  // TODO - implement PartialSun::PartialSun
  plantCount = 0;
}

void PartialSun::applyRays() {
  Iterator<Plant *> *plants = CreateIterator();
  plants->first();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> chance(0.0, 1.0);
  while (!plants->isDone()) {
    if (plants->currItem() != nullptr) {
      double roll = chance(gen);
      if (roll <= 0.1) {
        if (plants->currItem()->getStrategy() != "PartialSun") {
          if (plants->currItem()->getState() == "Dying") {
            plants->currItem()->setState(new Dead());
          } else if (plants->currItem()->getState() != "Dead") {
            plants->currItem()->createPlantMemento();
            plants->currItem()->setState(new Dying());
          }
          changed = true;
        } else {
          plants->currItem()->nextState();
        }
      }
    }
    plants->next();
  }
  if (changed) {
    this->notify();
    changed = false;
  }
}
