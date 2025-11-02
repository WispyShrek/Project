#include "Tulip.h"

Tulip::Tulip() {
  this->strategy = new ShadyCare();
  this->price = 50;
}

std::string Tulip::getName() { return "Tulip"; }

Tulip *Tulip::clone() { return new Tulip(*this); }

std::string Tulip::print() {
  std::string sprite;
  sprite.append("\x1B[38;5;202m <>");
  this->currState->print(sprite);
  return sprite;
}

double Tulip::getPrice() { return price; }

Tulip::Tulip(Tulip &toCopy) : Plant(toCopy) {}
