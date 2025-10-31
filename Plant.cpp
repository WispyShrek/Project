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


/*
#ifdef ENABLE_DOCTESTS
#include "doctest.h"
#include <sstream>
#include <memory>
#include "Plant.h"
#include "CareStrategy.h"
#include "PlantMemento.h"
#include "Sprout.h"
#include "Flowering.h"
#include "Mature.h"
#include "Dying.h"

class MockPlant : public Plant {
public:
    MockPlant() : Plant() {}
    MockPlant(const MockPlant& other) : Plant(other) {}
    std::string getName() override { return "MockPlant"; }
    Plant* clone() override { return new MockPlant(*this); }
};

class MockStrategy : public CareStrategy {
public:
    void applyCare() override {}
    std::string getStrategyName() override { return "MockStrategy"; }
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
    PlantMemento* m = p.createPlantMemento();
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
    auto* old = std::cout.rdbuf(cap.rdbuf());
    p.applyCare();
    std::cout.rdbuf(old);
    CHECK(cap.str().find("no care strategy selected yet") != std::string::npos);
}

TEST_CASE("setCareStrategy and getStrategy work") {
    MockPlant p;
    auto* s = new MockStrategy();
    p.setCareStrategy(s);
    CHECK(p.getStrategy() == "MockStrategy");
    // no delete here if Plant owns it; if not, uncomment:
    // delete s;
}

TEST_CASE("setStrategy (raw) also updates strategy name") {
    MockPlant p;
    auto* s = new MockStrategy();
    p.setStrategy(s);
    CHECK(p.getStrategy() == "MockStrategy");
}

TEST_CASE("increasePrice and getPrice reflect numeric value") {
    MockPlant p;
    double start = std::stod(p.getPrice());
    p.increasePrice(12.5);
    double after = std::stod(p.getPrice());
    CHECK(after == doctest::Approx(start + 12.5));
}

TEST_CASE("print writes current state's message") {
    MockPlant p;
    std::ostringstream cap;
    auto* old = std::cout.rdbuf(cap.rdbuf());
    p.print();
    std::cout.rdbuf(old);
    CHECK(cap.str().find("sprout") != std::string::npos);
}

TEST_CASE("operator== compares attributes (price change makes unequal)") {
    MockPlant a, b;
    CHECK( (a == b) == true );
    b.increasePrice(1.0);
    CHECK( (a == b) == false );
}

TEST_CASE("copy-constructing MockPlant clones state (and should copy price)") {
    MockPlant a;
    a.setState(new Flowering());
    a.increasePrice(23.7);
    MockPlant b(a);
    CHECK(b.getState() == "Flowering");
    CHECK(std::stod(b.getPrice()) == doctest::Approx(std::stod(a.getPrice())));
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
    CHECK(std::stod(c->getPrice()) == doctest::Approx(std::stod(a.getPrice())));
}
#endif
*/
