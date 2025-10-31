#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

/** @class PlantCreator
 * @brief An abstract factory class for creating Plant objects.
 * 
 * The PlantCreator class defines the interface for creating Plant instances.
 * Subclasses must implement the createPlant method to instantiate specific Plant types.
 */

class PlantCreator{
private:
	Plant* plant;

protected:
	virtual Plant* createPlant() = 0;

public:
	/** @fn PlantCreator::PlantCreator()
	 * @brief Constructor for the PlantCreator class.
	 */
	PlantCreator();
	/** @fn PlantCreator::~PlantCreator()
	 * @brief Destructor for the PlantCreator class.
	 */
	virtual ~PlantCreator();
};

#endif
