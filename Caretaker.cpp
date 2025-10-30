#include "Caretaker.h"

Caretaker::~Caretaker() {
	delete memento;
}

/**
 * @brief Retrieves the stored PlantMemento.
 * @return A pointer to the PlantMemento object.
 */
PlantMemento* Caretaker::getPlantMemento() {
	return memento; 
}

/**
 * @brief Stores a PlantMemento.
 * @param mem A pointer to the PlantMemento object to be stored. The Caretaker takes ownership of this memento.
 */
void Caretaker::setPlantMemento(PlantMemento* mem) {
	memento = mem;
}
