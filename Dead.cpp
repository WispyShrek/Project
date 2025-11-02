#include "Dead.h"
void Dead::next(Plant *context) {
  std::cout
      << "The plant is already dead and cannot transition to another state."
      << std::endl;
}
void Dead::print(std::string &sprite) {
  sprite.clear();
  sprite.append("\x1B[38;5;242m-\\");
}
PlantState *Dead::clone() const { return new Dead(*this); }
