#include "Flowering.h"

void Flowering::next(Plant *context) {
  if (!context)
    return;
  context->setState(new Mature());
  return;
}

PlantState *Flowering::clone() const { return new Flowering(*this); }

void Flowering::print(std::string &sprite) { sprite.append("\x1B[38;5;28m->"); }
