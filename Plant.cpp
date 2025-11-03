/**
 * @file Plant.cpp
 * @brief Implementation of the abstract Plant class.
 */
#include "Plant.h"
#include <cmath>
#include <iomanip>
#include <sstream>

/**
 * @brief Default constructor for the Plant class.
 * Initializes the plant in the 'Sprout' state with no care strategy.
 */
Plant::Plant()
    : currState(new Sprout()), strategy(nullptr), colour(), scent(), length(0), price(0.0)
{
}

/**
 * @brief Destructor for the Plant class.
 * Cleans up the dynamically allocated current state.
 */
Plant::~Plant()
{
  delete currState;
  currState = nullptr;
}

/**
 * @brief Gets the name of the current care strategy.
 * @return A string representing the name of the care strategy.
 */
std::string Plant::getStrategy() { return this->strategy->getStrategyName(); }

/**
 * @brief Gets the current state of the plant as a string.
 * @return A string representing the current state (e.g., "Sprout", "Flowering").
 */
std::string Plant::getState()
{
  if (dynamic_cast<Sprout *>(currState))
    return "Sprout";
  if (dynamic_cast<Flowering *>(currState))
    return "Flowering";
  if (dynamic_cast<Mature *>(currState))
    return "Mature";
  if (dynamic_cast<Dying *>(currState))
    return "Dying";
  if (dynamic_cast<Dead *>(currState))
    return "Dead";
  return "Unknown";
}

/**
 * @brief Increases the price of the plant.
 * @param amount The amount to add to the current price.
 */
void Plant::increasePrice(double amount)
{
  price += amount;
}

/**
 * @brief Sets the current state of the plant.
 * The Plant takes ownership of the provided state pointer.
 * @param state A pointer to the new PlantState.
 */
void Plant::setState(PlantState *state)
{
  currState = state;
}
void Plant::increasePrice(double amount) { price += amount; }
void Plant::setState(PlantState *state) { currState = state; }

/**
 * @brief Sets the care strategy for the plant.
 * @param strategy A pointer to the new CareStrategy.
 */
void Plant::setStrategy(CareStrategy *strategy) {
  this->strategy = strategy;
}

/**
 * @brief Gets the colour of the plant.
 * @return A string representing the plant's colour.
 */
std::string Plant::getColour() {
  return this->colour;
}

/**
 * @brief Gets the scent of the plant.
 * @return A string representing the plant's scent.
 */
std::string Plant::getScent() {
  return this->scent;
}

/**
 * @brief Gets the price of the plant as a string.
 * @return A string representing the plant's price.
 */
std::string Plant::getPrice() {
  return std::to_string(this->price);
}

/**
 * @brief Transitions the plant to its next logical state.
 * Delegates the state transition logic to the current state object.
 */
void Plant::nextState()
{
  if (currState)
    currState->next(this);
}

/**
 * @brief Transitions the plant to a previous or 'Dying' state.
 * A simple implementation that forces the state to 'Dying'.
 */
void Plant::prevState()
{
  if (!currState)
    return;
  if (dynamic_cast<Dying *>(currState))
    dynamic_cast<Dying *>(currState)->prev(this);
}

/**
 * @brief Sets or replaces the care strategy for the plant.
 * Manages memory by deleting the previous strategy if one exists.
 * @param strat A pointer to the new CareStrategy to set.
 */
void Plant::setCareStrategy(CareStrategy* strat) {
    if (strategy) { //replace previous strategy
        delete strategy; 
    }
    strategy = strat;
}

/**
 * @brief Applies the current care strategy to the plant.
 * If no strategy is set, it prints a warning message.
 */
void Plant::applyCare() {
    if (strategy)
        strategy->applyCare();
    else
        std::cout << "no care strategy selected yet\n";
}

/**
 * @brief Prints details about the plant's current state.
 * Delegates the printing logic to the current state object.
 */
void Plant::print()
{
  if (currState)
    currState->print();
  else
    std::cout << "Unknown plant state\n";
}

/**
 * @brief Associates a customer with this plant.
 * @param customer A pointer to the Customer object.
 */
void Plant::addCust(Customer *customer)
{
  this->customer = customer;
  std::cout << "Plant: this plant is now in a customer's cart.\n";
}
bool Plant::operator==(const Plant &other) {

    static const bool is_false = false;
    static const bool is_true = true;
    // Compare the relevant attributes of the plants
    if (colour != other.colour || scent != other.scent || length != other.length || price != other.price) {
        return is_false;
    }
        return is_true;
}

/**
 * @brief Creates a memento containing a snapshot of the plant's current state.
 * This is the Originator's method in the Memento pattern.
 * @return A pointer to a new PlantMemento object. The caller is responsible for its memory.
 */
PlantMemento* Plant::createPlantMemento() {
	return new PlantMemento(currState);
}

/**
 * @brief Restores the plant's state from a given memento.
 * This is the Originator's method in the Memento pattern.
 * @param memento A pointer to the PlantMemento containing the state to restore.
 */
void Plant::setPlantMemento(PlantMemento* memento) {
    if (memento) {
        delete currState; 
        currState = memento->getState();
    }
}

/**
 * @brief Copy constructor for the Plant class.
 * Performs a deep copy of the plant's state.
 * @param toCopy A reference to the Plant object to be copied.
 */
Plant::Plant(const Plant &toCopy)
    : currState(nullptr), strategy(toCopy.strategy), colour(toCopy.colour),
      scent(toCopy.scent), length(toCopy.length), price(toCopy.price)
{
  if (!toCopy.currState)
  {
    currState = nullptr;
  } else {
    currState = toCopy.currState->clone();
  }
}


#ifdef ENABLE_DOCTESTS
#include "CareStrategy.h"
#include "Dying.h"
#include "Flowering.h"
#include "Mature.h"
#include "Plant.h"
#include "PlantMemento.h"
#include "Sprout.h"
#include "doctest.h"
#include <memory>
#include <sstream>

class MockPlant : public Plant {
public:
  MockPlant() : Plant() {}
  MockPlant(const MockPlant &other) : Plant(other) {}
  std::string getName() override { return "MockPlant"; }
  Plant *clone() override { return new MockPlant(*this); }
};

class MockStrategy : public CareStrategy {
public:
  void applyCare() override {}
  std::string getStrategy() override { return "MockStrategy"; }
};

TEST_CASE("Plant default state is Sprout") {
  MockPlant p;
  CHECK(p.getState() == "Sprout");
}

TEST_CASE("setState updates reported state") {
  MockPlant p;
  p.setState(new Flowering());
  CHECK(p.getState() == "Flowering");
  p.setState(new Mature());
  CHECK(p.getState() == "Mature");
  p.setState(new Dying());
  CHECK(p.getState() == "Dying");
}

TEST_CASE("createPlantMemento / setPlantMemento restore previous state") {
  MockPlant p;
  p.setState(new Flowering());
  PlantMemento *m = p.createPlantMemento();
  p.setState(new Mature());
  CHECK(p.getState() == "Mature");
  p.setPlantMemento(m);
  CHECK(p.getState() == "Flowering");
  delete m;
}

TEST_CASE("prevState moves to Dying when not already Dying") {
  MockPlant p;
  p.setState(new Flowering());
  p.prevState();
  CHECK(p.getState() == "Dying");
  p.prevState();
  CHECK(p.getState() == "Dying");
}

TEST_CASE("applyCare without strategy prints warning") {
  MockPlant p;
  std::ostringstream cap;
  auto *old = std::cout.rdbuf(cap.rdbuf());
  p.applyCare();
  std::cout.rdbuf(old);
  CHECK(cap.str().find("no care strategy selected yet") != std::string::npos);
}

TEST_CASE("setCareStrategy and getStrategy work") {
  MockPlant p;
  auto *s = new MockStrategy();
  p.setCareStrategy(s);
  CHECK(p.getStrategy() == "MockStrategy");
  // no delete here if Plant owns it; if not, uncomment:
  // delete s;
}

TEST_CASE("setStrategy (raw) also updates strategy name") {
  MockPlant p;
  auto *s = new MockStrategy();
  p.setStrategy(s);
  CHECK(p.getStrategy() == "MockStrategy");
}

TEST_CASE("increasePrice and getPrice reflect numeric value") {
  MockPlant p;
  double start = std::stod(p.getPrice());
  p.increasePrice(12.5);
  double after = p.getPrice();
  CHECK(after == doctest::Approx(start + 12.5));
}

TEST_CASE("print writes current state's message") {
  MockPlant p;
  std::ostringstream cap;
  auto *old = std::cout.rdbuf(cap.rdbuf());
  p.print();
  std::cout.rdbuf(old);
  CHECK(cap.str().find("sprout") != std::string::npos);
}

TEST_CASE("operator== compares attributes (price change makes unequal)") {
  MockPlant a, b;
  CHECK((a == b) == true);
  b.increasePrice(1.0);
  CHECK((a == b) == false);
}

TEST_CASE("copy-constructing MockPlant clones state (and should copy price)") {
  MockPlant a;
  a.setState(new Flowering());
  a.increasePrice(23.7);
  MockPlant b(a);
  CHECK(b.getState() == "Flowering");
  CHECK(b.getPrice() == doctest::Approx(a.getPrice()));
}

TEST_CASE("setPlantMemento(nullptr) is a no-op") {
  MockPlant p;
  p.setState(new Mature());
  p.setPlantMemento(nullptr);
  CHECK(p.getState() == "Mature");
}

TEST_CASE("clone produces deep copy with same visible state") {
  MockPlant a;
  a.setState(new Mature());
  a.increasePrice(5.0);
  std::unique_ptr<Plant> c(a.clone());
  CHECK(c->getName() == "MockPlant");
  CHECK(c->getState() == "Mature");
  CHECK(c->getPrice() == doctest::Approx(a.getPrice()));
}
#endif
