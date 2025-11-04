#ifndef LIGHTSOFF_H
#define LIGHTSOFF_H

#include "Command.h"
#include "Light.h"

/** @class LightsOff
 * @brief A command class to turn off the lights in the greenhouse.
 *
 * The LightsOff class implements the Command interface and provides
 * functionality to turn off the light system when executed.
 */

class LightsOff : public Command {
private:
  Light *lights;

public:
  /** @fn LightsOff::LightsOff
   * @brief Constructor for the LightsOff class.
   */
  LightsOff(Light *lights);
  /** @fn void LightsOff::execute()
   * @brief Executes the command to turn off the lights.
   */
  void execute();
};

#endif

