#ifndef DYING_H
#define DYING_H
#include "Plant.h"
#include "PlantState.h"
#include "Dead.h"

/** @class Dying
 * @brief A class representing the dying state of a plant, derived from the PlantState base class.
 * 
 * The Dying class implements the behavior of a plant that is in the process of dying.
 * In this state, the plant may not transition to any other state unless specific care is applied.
 */

class Dying : public PlantState {
public:
  /** @fn void Dying::next(Plant *context) 
   * @brief Transitions the plant to the next state.
   * @param context A pointer to the Plant object whose state is to be changed.
  */
  void next(Plant *context);
  /** @fn void Dying::print()
   * @brief Prints the details of the dying state.
   */
  void print();
  /** @fn PlantState* Dying::clone() const
   * @brief Creates a clone of the Dying state.
   * @return A pointer to the newly created Dying state.
   */
  PlantState* clone() const override;
};

#endif