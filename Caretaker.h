/**
 * @file Caretaker.h
 * @brief Defines the Caretaker class for the Memento design pattern.
 */
#ifndef CARETAKER_H
#define CARETAKER_H
#include "PlantMemento.h"

/**
 * @class Caretaker
 * @brief Manages storing and retrieving a Plant's state using a PlantMemento.
 *
 * This class acts as the 'Caretaker' in the Memento design pattern. Its responsibility
 * is to hold onto a `PlantMemento` object. It does not inspect or modify the memento;
 * it simply keeps it safe for the `Plant` (the Originator) to retrieve later to
 * restore a previous state.
 */
class Caretaker{
private:
	/**
	 * @var PlantMemento* memento
	 * @brief A pointer to the stored memento object.
	 */
	PlantMemento* memento;
public:
	/**
	 * @brief Virtual destructor.
	 * Cleans up the stored memento to prevent memory leaks.
	 */
	virtual ~Caretaker();
	/**
	 * @brief Retrieves the stored memento.
	 * @return A pointer to the `PlantMemento` object.
	 */
	PlantMemento* getPlantMemento();
	/**
	 * @brief Sets the memento to be stored.
	 * The Caretaker takes responsibility for the provided memento.
	 * @param memento A pointer to the `PlantMemento` object to save.
	 */
	void setPlantMemento(PlantMemento* memento);
};

#endif
