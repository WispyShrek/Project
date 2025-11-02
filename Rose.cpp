#include "Rose.h"

Rose::Rose() {
  this->strategy = new SunnyCare();
  this->price = 80;
};

std::string Rose::getName() { return "Rose"; }

Rose *Rose::clone() { return new Rose(*this); }

std::string Rose::print() {
  std::string sprite;
  sprite.append("\x1B[38;5;196m@>");

  this->currState->print(sprite);
  return sprite;
}

double Rose::getPrice() { return price; }

Rose::Rose(Rose &toCopy) : Plant(toCopy) {}
