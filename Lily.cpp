#include "Lily.h"

Lily::Lily() {
  this->strategy = new PartialSunCare();
  this->price = 70;
};

std::string Lily::getName() { return "Lily"; }

Lily *Lily::clone() { return new Lily(*this); }

std::string Lily::print() {
  std::string sprite;
  sprite.append("\x1B[38;5;226m o");

  sprite.append("\x1B[38;5;231m}");
  this->currState->print(sprite);
  return sprite;
}

double Lily::getPrice() { return price; }

Lily::Lily(Lily &toCopy) : Plant(toCopy) {}
