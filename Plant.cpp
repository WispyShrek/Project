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
  currState = state;
}

void Plant::setStrategy(CareStrategy *strategy) {
  this->strategy = strategy;
}
std::string Plant::getColour() {
  return this->colour;
}
std::string Plant::getScent() {
  return this->scent;
}
std::string Plant::getPrice() {
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

void Plant::setCareStrategy(CareStrategy* strat) {
    if (strategy) { //replace previous strategy
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
  std::cout << "Plant: this plant is now in a customer's cart.\n";
}
const bool& Plant::operator==(const Plant& other) {

    // Compare the relevant attributes of the plants
    if (colour != other.colour || scent != other.scent || length != other.length || price != other.price) {
        return false;
    }
        return true;
}

PlantMemento* Plant::createPlantMemento() {
	// TODO - implement Plant::createPlantMemento
	return new PlantMemento(currState);
}

void Plant::setPlantMemento(PlantMemento* memento) {
	// TODO - implement Plant::setPlantMemento
    if (memento) {
        delete currState; 

        currState = memento->getState();
    }
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




#ifdef ENABLE_DOCTESTS
#include "doctest.h"
#include <sstream>
#include "Plant.h"
#include "Sprout.h"
#include "Flowering.h"
#include "Mature.h"
#include "Dying.h"
#include "PlantMemento.h"

TEST_CASE("Plant default state is Sprout") {
    Plant p;
    CHECK(p.getState() == "Sprout");
}

TEST_CASE("Plant setState changes reported state") {
    Plant p;
    p.setState(new Flowering());
    CHECK(p.getState() == "Flowering");
    p.setState(new Mature());
    CHECK(p.getState() == "Mature");
    p.setState(new Dying());
    CHECK(p.getState() == "Dying");
}

TEST_CASE("Plant memento restore brings back previous state") {
    Plant p;
    p.setState(new Flowering());
    PlantMemento* m = p.createPlantMemento();
    p.setState(new Mature());
    CHECK(p.getState() == "Mature");
    p.setPlantMemento(m);
    CHECK(p.getState() == "Flowering");
    delete m;
}

TEST_CASE("Plant prevState moves to Dying when not already Dying") {
    Plant p;
    p.setState(new Flowering());
    p.prevState();
    CHECK(p.getState() == "Dying");
}

TEST_CASE("Plant applyCare without strategy prints warning") {
    Plant p;
    std::ostringstream cap;
    auto* old = std::cout.rdbuf(cap.rdbuf());
    p.applyCare();
    std::cout.rdbuf(old);
    CHECK(cap.str().find("no care strategy selected yet") != std::string::npos);
}

TEST_CASE("Plant copy constructor clones state class") {
    Plant p;
    p.setState(new Flowering());
    Plant q(p);
    CHECK(q.getState() == "Flowering");
}
TEST_CASE("Plant equality operator compares attributes") {
    Plant p1;
    Plant p2;
    CHECK((p1 == p2) == true); // Initially equal

    // Modify an attribute in p2
    p2.increasePrice(10.0);
    CHECK((p1 == p2) == false); // Now should be unequal
}
TEST_CASE("Plant increasePrice updates price correctly") {
    Plant p;
    double initialPrice = std::stod(p.getPrice());
    p.increasePrice(15.5);
    double updatedPrice = std::stod(p.getPrice());
    CHECK(updatedPrice == initialPrice + 15.5);
}
TEST_CASE("Plant getColour and getScent return correct values") {
    Plant p;
    // Assuming default colour and scent are empty strings
    CHECK(p.getColour() == "");
    CHECK(p.getScent() == "");
}
TEST_CASE("Plant nextState transitions state correctly") {
    Plant p;
    p.nextState(); // From Sprout to Flowering
    CHECK(p.getState() == "Flowering");
    p.nextState(); // From Flowering to Mature
    CHECK(p.getState() == "Mature");
    p.nextState(); // From Mature to Dying
    CHECK(p.getState() == "Dying");
}
TEST_CASE("Plant print outputs current state") {
    Plant p;
    std::ostringstream cap;
    auto* old = std::cout.rdbuf(cap.rdbuf());
    p.print();
    std::cout.rdbuf(old);
    CHECK(cap.str().find("This is a sprout") != std::string::npos);
}
TEST_CASE("Plant setCareStrategy updates strategy") {
    Plant p;
    class MockStrategy : public CareStrategy {
    public:
        void applyCare() override {}
        std::string getStrategyName() override { return "MockStrategy"; }
    };
    MockStrategy* strat = new MockStrategy();
    p.setCareStrategy(strat);
    CHECK(p.getStrategy() == "MockStrategy");
    delete strat; // Clean up
}
TEST_CASE("Plant createPlantMemento and setPlantMemento work correctly") {
    Plant p;
    p.setState(new Flowering());
    PlantMemento* memento = p.createPlantMemento();
    p.setState(new Mature());
    CHECK(p.getState() == "Mature");
    p.setPlantMemento(memento);
    CHECK(p.getState() == "Flowering");
    delete memento;
}
TEST_CASE("Plant destructor cleans up state") {
    Plant* p = new Plant();
    p->setState(new Flowering());
    delete p; // Should not leak memory
}
TEST_CASE("Plant copy constructor with null state") {
    Plant p;
    p.setState(nullptr);
    Plant q(p);
    CHECK(q.getState() == "Sprout"); // Default to Sprout if null
}
#endif
