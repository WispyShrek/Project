#ifndef LILYCREATOR_H
#define LILYCREATOR_H

#include "Plant.h"
#include "PlantCreator.h"

/** @class LilyCreator
 * @brief A factory class for creating Lily plant objects.
 * 
 * The LilyCreator class inherits from PlantCreator and implements
 * the factory method to create Lily objects.
 */

class LilyCreator : public PlantCreator {
public:
  /** @fn LilyCreator::createPlant()
   * @brief Creates and returns a new Lily plant instance.
   * @return A pointer to the newly created Lily plant.
   */
  Plant *createPlant();
  /** @fn LilyCreator::LilyCreator()
   * @brief Constructor for the LilyCreator class.
   */
  LilyCreator();
};

#endif
