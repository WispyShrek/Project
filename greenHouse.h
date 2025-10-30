#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "Garden.h"
#include "Collection.h"
#include "GardenIterator.h"
#include <vector>

class greenHouse : public Collection<Garden*> {
private:
	std::vector<Garden*> gardens;
public:
	void powerSystem();
	/*! @fn Iterator<Garden*> *greenHouse::CreateIterator()
	 * @brief Creates an iterator for the greenhouse's garden collection.
	 * The CreateIterator function returns a new GardenIterator object that
	 * allows traversal of the gardens vector. The caller is responsible for
	 * deleting the returned iterator when finished.
	 * @return A pointer to a newly created Iterator<Garden*> object.
	 */
	Iterator<Garden*> *CreateIterator();
	/*! @fn void greenHouse::addItem(Garden *item)
	 * @brief Adds a garden to the greenhouse.
	 * The addItem function adds the given Garden pointer to the gardens vector.
	 * @param[in] item A pointer to a Garden object to be added to the greenhouse.
	 */
    void addItem(Garden* item);
	/*! @fn void greenHouse::removeItem(Garden *item)
	 * @brief Removes a garden from the greenhouse.
	 * The removeItem function searches for the given Garden pointer in the
	 * gardens vector and removes the first occurrence if found. If the garden is not
	 * found in the greenhouse, the function has no effect. Note that this function
	 * does not delete the Garden object; the caller is responsible for managing	
	 * its lifetime.
	 */
    void removeItem(Garden* item);
};

#endif
