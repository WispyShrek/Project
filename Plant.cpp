#include "Plant.h"

Plant::Plant() {
	// TODO - implement Plant::Plant
}

Plant::~Plant()
{
}

std::string Plant::getState() {
	// TODO - implement Plant::getState
	return "";
}

void Plant::setState(PlantState* state) {
	// TODO - implement Plant::setState
}

void Plant::nextState() {
	// TODO - implement Plant::nextState
}

void Plant::prevState() {
	// TODO - implement Plant::prevState
}

void Plant::applyCare() {
	// TODO - implement Plant::applyCare
}

void Plant::Print() {
	std::cout << "This is the plant print function." << std::endl;
}

void Plant::addCust() {
	// TODO - implement Plant::addCust
}

PlantMemento* Plant::createPlantMemento() {
	// TODO - implement Plant::createPlantMemento
	return nullptr;
}

void Plant::setPlantMemento(PlantMemento* memento) {
	// TODO - implement Plant::setPlantMemento
}

Plant::Plant(Plant& toCopy) {
	// TODO - implement Plant::Plant
}
