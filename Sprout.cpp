#include "Sprout.h"

void Sprout::next(Plant *context) {
  if (!context)
    return;
  context->setState(new Flowering());
}

void Sprout::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;40m->");
}
PlantState *Sprout::clone() const { return new Sprout(*this); }
