#include "Mature.h"

void Mature::next(Plant *context) {
  if (!context)
    return;
  std::cout << "Cannot grow more — already Mature.\n";
}

void Mature::print(std::string &sprite) { sprite.append("\x1B[38;5;28m,->>"); }
PlantState *Mature::clone() const { return new Mature(*this); }
