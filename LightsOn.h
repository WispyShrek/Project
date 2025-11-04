#ifndef LIGHTSON_H
#define LIGHTSON_H

#include "Command.h"
#include "Light.h"

/** @class LightsOn
 * @brief A command class to turn on the lights in the greenhouse.
 *
 * The LightsOn class implements the Command interface and provides
 * functionality to turn on the light system when executed.
 */

class LightsOn : public Command {
private:
  Light *lights;

public:
  /** @fn LightsOn::LIghtsOn()
   * @brief Constructor for the LightsOn class.
   */
  LightsOn(Light *lights);
  /** @fn LightsOn::execute()
   * @brief Executes the command to turn on the lights.
   */
  void execute();
};

#endif
