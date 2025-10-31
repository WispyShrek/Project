#ifndef LAVENDERCREATOR_H
#define LAVENDERCREATOR_H
#include "Plant.h"
#include "PlantCreator.h"

/** @class LavenderCreator
 * @brief A factory class for creating Lavender plant objects.
 * 
 * The LavenderCreator class inherits from PlantCreator and implements
 * the factory method to create Lavender objects.
 */

class LavenderCreator : public PlantCreator {
public:
  /** @fn LavenderCreator::createPlant()
   * @brief Creates and returns a new Lavender plant instance.
   * @return A pointer to the newly created Lavender plant.
   */
  Plant *createPlant();
  /** @fn LavenderCreator::LavenderCreator()
   * @brief Constructor for the LavenderCreator class.
   */
  LavenderCreator();
};

#endif
