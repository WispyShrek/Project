#include "Caretaker.h"

Caretaker::~Caretaker() {
	delete memento;
}

PlantMemento* Caretaker::getPlantMemento() {
	// TODO - implement Caretaker::getPlantMemento
	return memento; 
}

void Caretaker::setPlantMemento(PlantMemento* mem) {
	// TODO - implement Caretaker::setPlantMemento
	memento = mem;
}
// The Caretaker only stores the memento it shouldnt modifies it.

// memento stores a pointer to the Plant’s state (PlantState*), and can be retrieved by the originator.

// In a real system, you’d probably want to deep copy the state to avoid external modification, but for simplicity a pointer works.