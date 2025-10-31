#ifndef TULIPCREATOR_H
#define TULIPCREATOR_H

#include "PlantCreator.h"

/** @class TulipCreator
 * @brief A factory class for creating Tulip plant objects.
 * 
 * The TulipCreator class inherits from PlantCreator and implements
 * the factory method to create Tulip plant instances.
 */

class TulipCreator : public PlantCreator {
public:
  /** @fn Plant* TulipCreator::createPlant()
   * @brief Creates and returns a new Tulip plant object.
   * @return Pointer to the newly created Tulip object.
   */
  Plant *createPlant();
  /** @fn TulipCreator::TulipCreator()
   * @brief Constructor for the TulipCreator class.
   */
  TulipCreator();
};

#endif
