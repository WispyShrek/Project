#include "Dying.h"

void Dying::next(Plant *context) {
  // TODO - implement Dying::next
  return;
}

PlantState *Dying::clone() const { return new Dying(*this); }

void Dying::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;178m^-\\");
}
