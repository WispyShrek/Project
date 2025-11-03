#ifndef SPRINKLERSON_H
#define SPRINKLERSON_H

#include "Command.h"
#include "Sprinkler.h"

/** @class SprinklersOn
 * @brief A command class to turn on the sprinkler system.
 *
 * The SprinklersOn class implements the Command interface to provide
 * functionality for turning on the sprinkler system in the greenhouse.
 */

class SprinklersOn : public Command {
private:
  Sprinkler *sprinklers;

public:
  /** @fn SprinklersOn::SprinklersOn()
   * @brief Constructor for the SprinklersOn class.
   */
  SprinklersOn(Sprinkler *sprinklers);
  /** @fn void SprinklersOn::execute()
   * @brief Executes the command to turn on the sprinklers.
   */
  void execute();
};

#endif
