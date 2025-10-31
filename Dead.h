#ifndef DEAD_H
#define DEAD_H

#include "Plant.h"
#include "PlantState.h"

/** @class Dead
 * @brief A class representing the dead state of a plant, derived from the PlantState base class.
 * 
 * The Dead class implements the behavior of a plant that has reached the end of its lifecycle.
 * Once in the Dead state, the plant cannot transition to any other state.
 */

class Dead : public PlantState {
public:
  /** @fn void Dead::next(Plant *context)
   * @brief Transitions the plant to the next state.
   * @param context A pointer to the Plant object whose state is to be changed.
   */
  void next(Plant *context);
  /** @fn void Dead::print()
   * @brief Prints the details of the dead state.
   */
  void print();
  /** @fn PlantState* Dead::clone() const
   * @brief Creates a clone of the Dead state.
   * @return A pointer to the newly created Dead state.
   */
  PlantState* clone() const override;
};
 
#endif