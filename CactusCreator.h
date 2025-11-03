#ifndef CACTUSCREATOR_H
#define CACTUSCREATOR_H

#include "Plant.h"
#include "PlantCreator.h"

/** @class CactusCreator
 * @brief A factory class for creating Cactus plant objects.
 *
 * The CactusCreator class inherits from PlantCreator and implements
 * the factory method to create Cactus objects.
 */

class CactusCreator : public PlantCreator {
public:
  /** @fn CactusCreator::createPlant()
   * @brief Creates and returns a new Cactus plant instance.
   * @return A pointer to the newly created Cactus plant.
   */
  Plant *createPlant();
  /** @fn CactusCreator::CactusCreator()
   * @brief Constructor for the CactusCreator class.
   */
  CactusCreator();
};

#endif
