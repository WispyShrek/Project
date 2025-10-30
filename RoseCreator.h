#ifndef ROSECREATOR_H
#define ROSECREATOR_H

#include "PlantCreator.h"

/** @class RoseCreator
 * @brief A factory class for creating Rose plant objects.
 * 
 * The RoseCreator class inherits from PlantCreator and implements
 * the factory method to create Rose plant instances.
 */

class RoseCreator : public PlantCreator {
public:
  /** @fn Plant* RoseCreator::createPlant()
   * @brief Creates and returns a new Rose plant object.
   * @return Pointer to the newly created Rose object.
   */
  Plant *createPlant();
  /** @fn RoseCreator::RoseCreator()
   * @brief Constructor for the RoseCreator class.
   */
  RoseCreator();
};

#endif
