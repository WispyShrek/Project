/**
 * @file PlantMemento.h
 * @brief Definition of the PlantMemento class for the Memento design pattern.
 */
#ifndef PLANTMEMENTO_H
#define PLANTMEMENTO_H

#include "PlantState.h"

/**
 * @class PlantMemento
 * @brief Stores the internal state of a Plant object.
 *
 * The PlantMemento is part of the Memento design pattern. It is created by a
 * Plant (the Originator) to save its current state (a PlantState object).
 * The Caretaker can hold this memento and use it to restore the Plant's
 * state later, without having access to the state's implementation details.
 */
class PlantMemento{
private:
	/**
	 * @var PlantState* currState
	 * @brief A pointer to the saved state of the Plant.
	 */
	PlantState* currState;
public:
    /**
     * @brief Default constructor.
     * Initializes the memento with a null state.
     */
    PlantMemento();
    /**
     * @brief Constructor that captures a plant's state.
     * @param state A pointer to the PlantState to be saved. The memento creates a clone of this state.
     */
    PlantMemento(PlantState* state);
    /**
     * @brief Destructor.
     * Cleans up the stored PlantState clone.
     */
    ~PlantMemento();

    /**
     * @brief Retrieves the saved state.
     * @return A clone of the saved PlantState. The caller (the Plant) is responsible for managing this new object's memory.
     */
    PlantState* getState() const;
    /**
     * @brief Sets the state to be stored in the memento.
     * @param state A pointer to the PlantState to be saved. The memento creates a clone of this state.
     */
    void setState(PlantState* state);
};

#endif // PLANTMEMENTO_H
