#include "Plant.h"
#include <cmath>
#include <iomanip>
#include <sstream>

Plant::Plant()
    : currState(new Sprout()), strategy(nullptr), colour(), scent(), length(0) {
}

Plant::~Plant() {
  delete currState;
  currState = nullptr;
}
std::string Plant::getStrategy() { return this->strategy->getStrategyName(); }
std::string Plant::getDescription() {
  std::string mLineDescription;
  mLineDescription += "\nThis plant requires a " +
                      this->strategy->getStrategyName() +
                      "\n climate to flourish\n";
  mLineDescription += "\nCurrent state: " + this->getState() + "\n";
  return mLineDescription;
}
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
void Plant::increasePrice(double amount) { price += amount; }
void Plant::setState(PlantState *state) { currState = state; }

void Plant::setStrategy(CareStrategy *strategy) { this->strategy = strategy; }
std::string Plant::getColour() { return this->colour; }
std::string Plant::getScent() { return this->scent; }
double Plant::getPrice() { return this->price; }

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

void Plant::setCareStrategy(CareStrategy *strat) {
  if (strategy) { // replace previous strategy
    delete strategy;
  }
  strategy = strat;
}

void Plant::applyCare() {
  // TODO - implement Plant::applyCare
  if (strategy)
    strategy->applyCare();
  else
    std::cout << "no care strategy selected yet\n";
}

std::string Plant::print() {
  if (currState) {
    std::string sprite;
    currState->print(sprite);
    return sprite;
  }
  return "";
}

void Plant::addCust(Customer *customer) {
  this->customer = customer;
  std::cout << "Plant: this plant is now in a customer's cart.\n";
}
bool Plant::operator==(const Plant &other) {

  // Compare the relevant attributes of the plants
  if (colour != other.colour || scent != other.scent ||
      length != other.length || price != other.price) {
    return false;
  }
  return true;
}

PlantMemento *Plant::createPlantMemento() {
  // TODO - implement Plant::createPlantMemento
  return new PlantMemento(currState);
}

void Plant::setPlantMemento(PlantMemento *memento) {
  // TODO - implement Plant::setPlantMemento
  if (memento) {
    delete currState;

    currState = memento->getState();
  }
}

Plant::Plant(Plant &toCopy)
    : currState(nullptr), strategy(toCopy.strategy), colour(toCopy.colour),
      scent(toCopy.scent), length(toCopy.length), price(toCopy.price) {
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
