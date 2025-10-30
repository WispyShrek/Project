#include "Plant.h"

Plant::Plant()
    : currState(new Sprout()), strategy(nullptr), colour(), scent(), length(0) {
}

Plant::~Plant() {
  delete currState;
  currState = nullptr;
}
std::string Plant::getStrategy() { return this->strategy->getStrategyName(); }
std::string Plant::getState() {
  // TODO - implement Plant::getState
  if (dynamic_cast<Sprout *>(currState))
    return "Sprout";
  if (dynamic_cast<Flowering *>(currState))
    return "Flowering";
  if (dynamic_cast<Mature *>(currState))
    return "Mature";
  if (dynamic_cast<Dying *>(currState))
    return "Dying";
  return "Unknown";
}

void Plant::setState(PlantState *state) {
  // TODO - implement Plant::setState
  currState = state;
}

void Plant::nextState() {
  // TODO - implement Plant::nextState
  if (currState)
    currState->next(this);
}

void Plant::prevState() {
  // TODO - implement Plant::prevState
  if (!currState)
    return;
  if (!dynamic_cast<Dying *>(currState))
    setState(new Dying());
}

/**
 * @brief Sets the care strategy for the plant.
 * @param strat A pointer to the CareStrategy to be used. The Plant takes ownership of this strategy object and will delete any previously set strategy.
 */
void Plant::setCareStrategy(CareStrategy* strat) {
    if (strategy) { //replace previous strategy
        delete strategy; 
    }
    strategy = strat;
}

/**
 * @brief Applies the current care strategy to the plant.
 * Delegates the care action to the concrete strategy object.
 */
void Plant::applyCare() {
	// TODO - implement Plant::applyCare
    if (strategy)
        strategy->applyCare();
    else
        std::cout << "no care strategy selected yet\n";
}

void Plant::print() {
  if (currState)
    currState->print();
  else
    std::cout << "Unknown plant state\n";
}

void Plant::addCust() {
  // TODO - implement Plant::addCust
}

/**
 * @brief Creates a memento containing a snapshot of the plant's current state.
 * @return A pointer to a new PlantMemento object. The caller is responsible for managing the memory of this memento.
 */
PlantMemento* Plant::createPlantMemento() {
	// TODO - implement Plant::createPlantMemento
	return new PlantMemento(currState);
}

/**
 * @brief Restores the plant's state from a memento.
 * @param memento A pointer to the PlantMemento object containing the state to restore. The plant does not take ownership of the memento itself.
 */
void Plant::setPlantMemento(PlantMemento* memento) {
	// TODO - implement Plant::setPlantMemento
    if (memento) {
        delete currState; 

        currState = memento->getState();
    }
}

Plant::Plant(Plant &toCopy)
    : currState(nullptr), strategy(toCopy.strategy), colour(toCopy.colour),
      scent(toCopy.scent), length(toCopy.length) {
  if (!toCopy.currState) {
    currState = nullptr;
  } else if (dynamic_cast<Sprout *>(toCopy.currState)) {
    currState = new Sprout();
  } else if (dynamic_cast<Flowering *>(toCopy.currState)) {
    currState = new Flowering();
  } else if (dynamic_cast<Mature *>(toCopy.currState)) {
    currState = new Mature();
  } else if (dynamic_cast<Dying *>(toCopy.currState)) {
    currState = new Dying();

  } else {
    // Safe fallback
    currState = new Sprout();
  }
}
