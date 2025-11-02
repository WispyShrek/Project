#ifndef MATURE_H
#define MATURE_H

#include "Plant.h"
#include "PlantState.h"

/** @class Mature
 * @brief A class representing the mature state of a plant, derived from the
 * PlantState base class.
 *
 * The Mature class implements the behavior of a plant that has reached
 * maturity. In this state, the plant can transition to other states based on
 * care and conditions.
 */

class Mature : public PlantState {
public:
  /** @fn void Mature::next(Plant *context)
   * @brief Transitions the plant to the next state.
   * @param context A pointer to the Plant object whose state is to be changed.
   */
  void next(Plant *context) override;
  /** @fn void Mature::print()
   * @brief Prints the details of the mature state.
   */
  void print(std::string &sprite) override;
  /** @fn PlantState* Mature::clone() const
   * @brief Creates a clone of the Mature state.
   * @return A pointer to the newly created Mature state.
   */
  PlantState *clone() const override;
};

#endif
