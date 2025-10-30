#include "Dead.h"
void Dead::next(Plant *context) {
    std::cout << "The plant is already dead and cannot transition to another state." << std::endl;
}
void Dead::print() {
    std::cout << "The plant is dead." << std::endl;
}
PlantState* Dead::clone() const {
    return new Dead(*this);
}