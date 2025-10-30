#include "PlantMemento.h"

PlantMemento::PlantMemento() : currState(nullptr) {}

PlantMemento::PlantMemento(PlantState* state) {
    currState = state ? state->clone() : nullptr;
}

PlantMemento::~PlantMemento() {
    delete currState;
}

PlantState* PlantMemento::getState() const {
    // Return a CLONE of the internal state.
    // The Plant (Originator) will take ownership of this new copy.
    return currState ? currState->clone() : nullptr;
}

void PlantMemento::setState(PlantState* state) {
    delete currState;
    currState = state ? state->clone() : nullptr;
}
