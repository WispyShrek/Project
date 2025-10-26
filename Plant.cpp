#include "Plant.h"

Plant::Plant()
: currState(new Sprout()),
  strategy(nullptr),
  colour(),
  scent(),
  length(0)
{}

Plant::~Plant()
{
	delete currState;
    currState = nullptr;
}

std::string Plant::getState() {
	// TODO - implement Plant::getState
    if (dynamic_cast<Sprout*>(currState))    return "Sprout";
    if (dynamic_cast<Flowering*>(currState)) return "Flowering";
    if (dynamic_cast<Mature*>(currState))    return "Mature";
    if (dynamic_cast<Dying*>(currState))     return "Dying";
	return "Unknown";
}

void Plant::setState(PlantState* state) {
	// TODO - implement Plant::setState
    currState = state; 
}

void Plant::nextState() {
	// TODO - implement Plant::nextState
    if (currState) currState->next(this);
}

void Plant::prevState() {
	// TODO - implement Plant::prevState
	//working on
}

void Plant::applyCare() {
	// TODO - implement Plant::applyCare
}

void Plant::print() {
    std::cout << "Plant state=" << getState()
              << " colour=" << colour
              << " scent="  << scent
              << " length=" << length
              << std::endl;
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

Plant::Plant(Plant& toCopy) : currState(nullptr), strategy(toCopy.strategy), colour(toCopy.colour), scent(toCopy.scent), length(toCopy.length)
{
    if (!toCopy.currState) {
        currState = nullptr;
    } else if (dynamic_cast<Sprout*>(toCopy.currState)) {
        currState = new Sprout();
    } else if (dynamic_cast<Flowering*>(toCopy.currState)) {
        currState = new Flowering();
    } else if (dynamic_cast<Mature*>(toCopy.currState)) {
        currState = new Mature();
    } else if (dynamic_cast<Dying*>(toCopy.currState)) {
        currState = new Dying();

    } else {
        // Safe fallback
        currState = new Sprout();
	}
}
