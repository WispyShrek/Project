#ifndef GREENHOUSECONTROLLER_H
#define GREENHOUSECONTROLLER_H
#include "Command.h"
#include "SprinklersOn.h"
#include "SprinklersOff.h"

/** @class GreenhouseController
 * @brief A controller class for managing greenhouse systems like sprinklers and lights.
 * 
 * The GreenhouseController class uses the Command design pattern to encapsulate
 * requests to turn on/off sprinklers and lights in the greenhouse.
 */
 
class GreenhouseController{
private:
	Command* SprinklersUpCommand;
	Command* SprinklersdownCommand;
	Command* lightUpCommand;
	Command* lightDownCommand;

public:
	/** @fn GreenhouseController::GreenhouseController()
	 * @brief Constructor for GreenhouseController class.
	 */
	GreenhouseController();
	/** @fn GreenhouseController::~GreenhouseController()
	 * @brief Destructor for GreenhouseController class.
	 */
	~GreenhouseController();

	/** @fn void GreenhouseController::setSprinklerCommands(Command* on, Command* off)
	 * @brief Sets the commands for turning sprinklers on and off.
	 * @param on Pointer to the command to turn sprinklers on.
	 * @param off Pointer to the command to turn sprinklers off.
	 */
	void setSprinklerCommands(Command* on, Command* off);
	/** @fn void GreenhouseController::setLightCommands(Command* on, Command* off)
	 * @brief Sets the commands for turning lights on and off.
	 * @param on Pointer to the command to turn lights on.
	 * @param off Pointer to the command to turn lights off.
	 */
	void setLightCommands(Command* on, Command* off);



	/** @fn void GreenhouseController::flipUpSprinklers()
	 * @brief Activates the command to turn on the sprinklers.
	 */
	void flipUpSprinklers();
	/** @fn void GreenhouseController::flipDownSprinklers()
	 * @brief Activates the command to turn off the sprinklers.
	 */
	void flipDownSprinklers();
	/** @fn void GreenhouseController::flipUpLights()
	 * @brief Activates the command to turn on the lights.
	 */
	void flipUpLights();
	/** @fn void GreenhouseController::flipDownLights()
	 * @brief Activates the command to turn off the lights.
	 */
	void flipDownLights();
};

#endif