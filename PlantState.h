#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>
class Plant;

/** @class PlantState
 * @brief An abstract base class representing the state of a plant.
 * 
 * The PlantState class defines the interface for different states of a plant,
 * including methods for transitioning to the next state, printing state details,
 * and cloning the state.
 */

class PlantState {
public:
    /** @fn PlantState::~PlantState()
     * @brief Virtual destructor for the PlantState class.
     */
    virtual ~PlantState() {}  
    virtual void next(Plant *context) = 0;
    virtual void print() = 0;
    virtual PlantState* clone() const = 0; // to copy the state over in memento
};

#endif
