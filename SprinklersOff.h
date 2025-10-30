#ifndef SPRINKLERSOFF_H
#define SPRINKLERSOFF_H

#include "Command.h"
#include "Sprinkler.h"

/** @class SprinklersOff
 * @brief A command class to turn off the sprinkler system.
 * 
 * The SprinklersOff class implements the Command interface to provide
 * functionality for turning off the sprinkler system in the greenhouse.
 */

class SprinklersOff : public Command {
private:
  Sprinkler *sprinklers;
public:
  /** @fn SprinklersOff::SprinklersOff()
   * @brief Constructor for the SprinklersOff class.
   */
  SprinklersOff();
  /** @fn void SprinklersOff::execute()
   * @brief Executes the command to turn off the sprinklers.
   */
  void execute();
};

#endif
