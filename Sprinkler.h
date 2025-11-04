#ifndef SPRINKLER_H
#define SPRINKLER_H

class greenHouse;
/** @class Sprinkler
 * @brief A class representing a sprinkler system in the greenhouse.
 *
 * The Sprinkler class provides methods to turn the sprinkler on and off.
 */

class Sprinkler {
private:
  greenHouse *greenhouse;

public:
  /** @fn Sprinkler::Sprinkler()
   * @brief Constructor for the Sprinkler class.
   */
  Sprinkler(greenHouse *greenhouse);
  void turnOn();
  /** @fn Sprinkler::turnOff()
   * @brief Turns off the sprinkler.
   */
  void turnOff();
};

#endif
