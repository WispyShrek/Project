#ifndef FLOWERING_H
#define FLOWERING_H
#include "Plant.h"
#include "PlantState.h"

/** @class Flowering
 * @brief A class representing the flowering state of a plant, derived from the PlantState base class.
 * 
 * The Flowering class implements the behavior of a plant that is in the flowering stage.
 * In this state, the plant can transition to the Mature state upon receiving care.
*/

class Flowering : public PlantState {
public:
  /** @fn void Flowering::next(Plant *context)
   * @brief Transitions the plant to the next state.
   * @param context A pointer to the Plant object whose state is to be changed.
   */
  void next(Plant *context);
  /** @fn void Flowering::print()
   * @brief Prints the details of the flowering state.
   */
  void print();
  /** @fn PlantState* Flowering::clone() const
   * @brief Creates a clone of the Flowering state.
   * @return A pointer to the newly created Flowering state.
   */
  PlantState* clone() const override;
};

#endif