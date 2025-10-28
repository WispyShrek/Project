#include "Plant.h"

Plant::Plant()
    : currState(new Sprout()), strategy(nullptr), colour(), scent(), length(0)
{
}

Plant::~Plant()
{
  delete currState;
  currState = nullptr;
}
std::string Plant::getStrategy() { return this->strategy->getStrategyName(); }
std::string Plant::getState()
{
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
void Plant::increasePrice(double amount)
{
  price += amount;
}
void Plant::setState(PlantState *state)
{
  // TODO - implement Plant::setState
  currState = state;
}

void Plant::setStrategy(CareStrategy *strategy) {
  this->strategy = strategy;
}
string Plant::getColour() {
  return this->colour;
}
string Plant::getScent() {
  return this->scent;
}
string Plant::getPrice() {
  return std::to_string(this->price);
}

void Plant::nextState()
{
  // TODO - implement Plant::nextState
  if (currState)
    currState->next(this);
}

void Plant::prevState()
{
  // TODO - implement Plant::prevState
  if (!currState)
    return;
  if (!dynamic_cast<Dying *>(currState))
    setState(new Dying());
}

void Plant::applyCare()
{
  if (currState)
    currState->next(this);
}

void Plant::print()
{
  if (currState)
    currState->print();
  else
    std::cout << "Unknown plant state\n";
}

void Plant::addCust(Customer *customer)
{
  this->customer = customer;
  cout << "Plant: this plant is now in a customer's cart.\n";
}
const bool& Plant::operator==(const Plant& other) {

    // Compare the relevant attributes of the plants
    if (colour != other.colour || scent != other.scent || length != other.length || price != other.price) {
        return false;
    }

    // If all attributes match, return this plant
    return true;
}
PlantMemento *Plant::createPlantMemento()
{
  // TODO - implement Plant::createPlantMemento
  return nullptr;
}

void Plant::setPlantMemento(PlantMemento *memento)
{
  // TODO - implement Plant::setPlantMemento
}

Plant::Plant(Plant &toCopy)
    : currState(nullptr), strategy(toCopy.strategy), colour(toCopy.colour),
      scent(toCopy.scent), length(toCopy.length)
{
  if (!toCopy.currState)
  {
    currState = nullptr;
  }
  else if (dynamic_cast<Sprout *>(toCopy.currState))
  {
    currState = new Sprout();
  }
  else if (dynamic_cast<Flowering *>(toCopy.currState))
  {
    currState = new Flowering();
  }
  else if (dynamic_cast<Mature *>(toCopy.currState))
  {
    currState = new Mature();
  }
  else if (dynamic_cast<Dying *>(toCopy.currState))
  {
    currState = new Dying();
  }
  else
  {
    // Safe fallback
    currState = new Sprout();
  }
}
