#include "Lavender.h"

Lavender::Lavender() {
  this->strategy = new PartialSunCare();
  this->price = 60;
};

std::string Lavender::getName() { return "Lavender"; }

Lavender *Lavender::clone() { return new Lavender(*this); }

std::string Lavender::print() {
  std::string sprite;
  sprite.append("\x1B[38;5;128m >>>");
  this->currState->print(sprite);
  return sprite;
}

double Lavender::getPrice() { return price; }

Lavender::Lavender(Lavender &toCopy) : Plant(toCopy) {}
