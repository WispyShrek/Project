#ifndef SPRINKLER_H
#define SPRINKLER_H

/** @class Sprinkler
 * @brief A class representing a sprinkler system in the greenhouse.
 *
 * The Sprinkler class provides methods to turn the sprinkler on and off.
 */

#include "greenHouse.h"
class Sprinkler {
private:
  greenHouse *greenhouse;

public:
  /** @fn Sprinkler::Sprinkler()
   * @brief Constructor for the Sprinkler class.
   */
  void turnOn();
  /** @fn Sprinkler::turnOff()
   * @brief Turns off the sprinkler.
   */
  void turnOff();
};

#endif
