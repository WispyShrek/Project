#ifndef LIGHT_H
#define LIGHT_H

/** @class Light
 * @brief A class representing a light system in the greenhouse.
 * 
 * The Light class provides methods to turn the lights on and off.
 */

class Light {
public:
	/** @fn Light::Light()
	 * @brief Constructor for the Light class.
	 */
	void turnOn();
	/** @fn Light::turnOff()
	 * @brief Turns off the light.
	 */
	void turnOff();
};

#endif
 