#include "PlantMemento.h"

/**
 * @brief Default constructor for PlantMemento.
 * Initializes the memento with a null state.
 */
PlantMemento::PlantMemento() : currState(nullptr) {}

/**
 * @brief Constructs a PlantMemento by saving a clone of a PlantState.
 * @param state The PlantState to be stored in the memento. A deep copy is made to ensure the memento's state is independent of the original object's state.
 */
PlantMemento::PlantMemento(PlantState* state) {
    currState = state ? state->clone() : nullptr;
}

/**
 * @brief Destructor for PlantMemento.
 * Cleans up by deleting the stored PlantState to prevent memory leaks.
 */
PlantMemento::~PlantMemento() {
    delete currState;
}

/**
 * @brief Retrieves the state stored in the memento.
 * @return A clone of the stored PlantState. The caller (the Originator) takes ownership of this new copy and is responsible for its memory management.
 */
PlantState* PlantMemento::getState() const {
    return currState ? currState->clone() : nullptr;
}

/**
 * @brief Sets the state of the memento.
 * @param state The new PlantState to be stored. A clone of the state is created, and the previously held state is deleted.
 */
void PlantMemento::setState(PlantState* state) {
    delete currState;
    currState = state ? state->clone() : nullptr;
}
