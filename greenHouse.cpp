#include "greenHouse.h"
#include "AridCare.h"
#include "GreenhouseController.h"
#include "Light.h"
#include "LightsOff.h"
#include "LightsOn.h"
#include "PartialSun.h"
#include "PartialSunCare.h"
#include "Rose.h"
#include "Shady.h"
#include "ShadyCare.h"
#include "Sprinkler.h"
#include "Sunny.h"
#include <random>
#include <regex>
#include <string>

int visible_ghlength(const std::string &s) {
  static const std::regex ansi_escape("\033\\[[0-9;]*m");
  std::string clean = std::regex_replace(s, ansi_escape, "");
  return static_cast<int>(clean.size());
}
greenHouse::greenHouse() { this->carestrategy = new PartialSunCare(); }
greenHouse::~greenHouse() {
  for (auto &row : plants) {
    for (auto *&p : row) {
      p = nullptr;
    }
  }
}

void greenHouse::tick() {
  if (wet && bright) {
    this->carestrategy = new SunnyCare();
  } else if ((!wet) && bright) {
    this->carestrategy = new AridCare();
  } else if ((!wet) && (!bright)) {
    this->carestrategy = new PartialSunCare();
  } else if ((wet) && (!bright)) {
    this->carestrategy = new ShadyCare();
  }

  Iterator<Plant *> *plants = CreateIterator();
  plants->first();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> chance(0.0, 1.0);
  while (!plants->isDone()) {
    if (plants->currItem() != nullptr) {
      double roll = chance(gen);
      if (roll <= 0.2) {
        if (plants->currItem()->getStrategy() !=
            this->carestrategy->getStrategyName()) {
          if (plants->currItem()->getState() == "Dying") {
            plants->currItem()->setState(new Dead());
          } else if (plants->currItem()->getState() != "Dead") {
            Caretaker *caretaker = new Caretaker();
            caretaker->setPlantMemento(
                plants->currItem()->createPlantMemento());
            plants->currItem()->setState(new Dying(caretaker));
          }
        } else {
          plants->currItem()->nextState();
        }
      } else if (roll <= 0.3) {
        plants->currItem()->nextState();
      }
    }
    plants->next();
  }
}

GreenhouseController *greenHouse::powerSystem() {
  Sprinkler *sprinklers = new Sprinkler(this);
  Light *lights = new Light(this);
  GreenhouseController *controller = new GreenhouseController();
  controller->setLightCommands(new LightsOn(lights), new LightsOff(lights));
  controller->setSprinklerCommands(new SprinklersOn(sprinklers),
                                   new SprinklersOff(sprinklers));
  return controller;
}

Iterator<Plant *> *greenHouse::CreateIterator() {
  return new PlantIterator(plants);
}
Plant *greenHouse::removeDying() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (plants[r][c] != nullptr) {
        if (plants[r][c]->getState() == "Dying") {
          Plant *toHarvest = plants[r][c];
          plantCount--;
          plants[r][c] = nullptr;
          return toHarvest;
        }
      }
    }
  }
  return nullptr;
}

Plant *greenHouse::removeMature() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (plants[r][c] != nullptr) {
        if (plants[r][c]->getState() == "Mature") {
          Plant *toHarvest = plants[r][c];
          plantCount--;
          plants[r][c] = nullptr;
          return toHarvest;
        }
      }
    }
  }
  return nullptr;
}

bool greenHouse::addItem(Plant *item, int row, int col) {
  if (plantCount > 9) {
    return false;
  }
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    return false;
  }
  if (plants[row][col] != nullptr) {
    return false;
  }
  plants[row][col] = item;
  ++plantCount;
  return true;
}

bool greenHouse::tryAddItem(Plant *item) {
  // place in first free slot (row-major)
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      if (plants[r][c] == nullptr) {
        plants[r][c] = item;
        ++plantCount;
        return true;
      }
    }
  }
  // Fallback if grid has no free slot but count <= 9
  return false;
}

bool greenHouse::removeItem(Plant *item) {
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      if (plants[r][c] == item) {
        plants[r][c] = nullptr;
        --plantCount;
        return true;
      }
    }
  }
  return false;
}

std::string greenHouse::print() {
  std::string gardenSprite;
  std::string row;
  std::string plant;
  int fillLength;
  gardenSprite.append("\x1B[38;5;172m");
  for (int r = 0; r < 3; r++) {
    gardenSprite.append(36, '|');
    gardenSprite.append("\n\x1B[38;5;172m");
    row.clear();
    row.append("|||");
    for (int c = 0; c < 3; c++) {
      plant.clear();
      plant.shrink_to_fit();
      if (plants[r][c] == nullptr) {
        row.append("||||||||");
      } else {
        plant = plants[r][c]->print();
        if (visible_ghlength(plant) < 8) {
          int pad = (8 - visible_ghlength(plant)) / 2;
          plant.append("\x1B[38;5;172m");
          plant.insert(0, pad, '|');
        }
        row.append(plant);
        row.append(1, '|');
        row.append("\x1B[38;5;172m");
      }
      row.append("|||\x1B[38;5;172m");
    }
    gardenSprite.append(row);
    fillLength = 36 - visible_ghlength(row);
    if (fillLength < 0) {
      fillLength = 0;
    }
    gardenSprite.append(fillLength, '|');
    gardenSprite.append("\n\x1B[38;5;172m");
  }
  gardenSprite.append(36, '|');
  gardenSprite.append("\n\x1B[38;5;172m");

  return gardenSprite;
}

std::string greenHouse::getDescription() {
  std::string description;
  description += "Climate: " + this->carestrategy->getStrategyName();
  description += "\nSoil: ";
  description += (wet) ? "wet" : "dry";
  description += "\nLight level: ";
  description += (bright) ? "bright" : "dark";
  return description;
}

#ifdef ENABLE_DOCTESTS
#include "GreenhouseController.h"
#include "Rose.h"
#include "doctest.h"
#include "greenHouse.h"
#include <sstream>
#include <string>
#include <vector>

<<<<<<< HEAD TEST_CASE(
    "greenHouse::powerSystem emits controller calls in order (unwired)") {
  greenHouse gh;
  std::ostringstream cap;
  auto *old = std::cerr.rdbuf(cap.rdbuf());
  gh.powerSystem();
  std::cerr.rdbuf(old);
  const std::string out = cap.str();
  auto p1 = out.find("SprinklersUpCommand not set");
  auto p2 = out.find("lightUpCommand not set");
  auto p3 = out.find("SprinklersdownCommand not set");
  auto p4 = out.find("lightDownCommand not set");
  CHECK(p1 != std::string::npos);
  CHECK(p2 != std::string::npos);
  CHECK(p3 != std::string::npos);
  CHECK(p4 != std::string::npos);
  CHECK(p1 < p2);
  CHECK(p2 < p3);
  CHECK(p3 < p4);
}

TEST_CASE("greenHouse::addItem(row,col) places plants; iterator visits "
          "in row-major order") {
  greenHouse gh;
  Plant *p0 = new Rose();
  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
=======
TEST_CASE("greenHouse::powerSystem emits controller calls in order (unwired)") {
  greenHouse gh;
  std::ostringstream cap;
  auto *old = std::cerr.rdbuf(cap.rdbuf());
  gh.powerSystem();
  std::cerr.rdbuf(old);
  const std::string out = cap.str();
  auto p1 = out.find("SprinklersUpCommand not set");
  auto p2 = out.find("lightUpCommand not set");
  auto p3 = out.find("SprinklersdownCommand not set");
  auto p4 = out.find("lightDownCommand not set");
  CHECK(p1 != std::string::npos);
  CHECK(p2 != std::string::npos);
  CHECK(p3 != std::string::npos);
  CHECK(p4 != std::string::npos);
  CHECK(p1 < p2);
  CHECK(p2 < p3);
  CHECK(p3 < p4);
}

TEST_CASE("greenHouse::addItem(row,col) places plants; iterator visits in "
          "row-major order") {
  greenHouse gh;
  Plant *p0 = new Rose();
  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
>>>>>>> Dev

  gh.addItem(p0, 0, 0); // (0,0)
  gh.addItem(p1, 0, 2); // (0,2)
  gh.addItem(p2, 1, 0); // (1,0)
  gh.addItem(p3, 2, 1); // (2,1)

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  REQUIRE(it->isDone() == false);
  CHECK(it->currItem() == p0); // (0,0)
  it->next();
  CHECK(it->currItem() == p1); // (0,2)
  it->next();
  CHECK(it->currItem() == p2); // (1,0)
  it->next();
  CHECK(it->currItem() == p3); // (2,1)
  it->next();
  CHECK(it->isDone() == true);

  delete it;
}

<<<<<<< HEAD
TEST_CASE("greenHouse iterator skips null cells") {
  greenHouse gh;
  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
=======
TEST_CASE("greenHouse iterator skips null cells") {
  greenHouse gh;
  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
>>>>>>> Dev

  gh.addItem(p1, 0, 0);
  gh.addItem(p2, 2, 2);

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  REQUIRE(it->isDone() == false);
  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p2);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
}

<<<<<<< HEAD
TEST_CASE("greenHouse::addItem(row,col) rejects invalid indices and "
          "occupied cells") {
  greenHouse gh;

  Plant *a = new Rose();
  Plant *b = new Rose();
  Plant *c = new Rose();

  gh.addItem(a, 1, 1);
  gh.addItem(b, 1, 1);  // occupied - should not add
  gh.addItem(c, -1, 0); // invalid - should not add

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
TEST_CASE(
    "greenHouse::addItem(row,col) rejects invalid indices and occupied cells") {
  greenHouse gh;

  Plant *a = new Rose();
  Plant *b = new Rose();
  Plant *c = new Rose();

  gh.addItem(a, 1, 1);
  gh.addItem(b, 1, 1);  // occupied - should not add
  gh.addItem(c, -1, 0); // invalid - should not add

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  REQUIRE(it->isDone() == false);
  CHECK(it->currItem() == a);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete b; // not added
  delete c; // not added
}

<<<<<<< HEAD
TEST_CASE("greenHouse::addItem(auto) fills first free slot in row-major "
          "order") {
  greenHouse gh;

  Plant *pA = new Rose();
  Plant *pB = new Rose();
  Plant *pC = new Rose();
=======
TEST_CASE(
    "greenHouse::addItem(auto) fills first free slot in row-major order") {
  greenHouse gh;

  Plant *pA = new Rose();
  Plant *pB = new Rose();
  Plant *pC = new Rose();
>>>>>>> Dev

  gh.addItem(pA, 0, 0);
  gh.addItem(pB, 0, 1);
  gh.tryAddItem(pC); // should go to (0,2)

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  CHECK(it->currItem() == pA);
  it->next();
  CHECK(it->currItem() == pB);
  it->next();
  CHECK(it->currItem() == pC);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
}

<<<<<<< HEAD
TEST_CASE("greenHouse::addItem respects maximum capacity of 7 plants") {
  greenHouse gh;

  std::vector<Plant *> ps;
  for (int i = 0; i < 8; i++)
    ps.push_back(new Rose());

  for (int i = 0; i < 7; i++)
    gh.addItem(ps[i]);
  gh.addItem(ps[7]); // should be rejected

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();

  int count = 0;
  while (!it->isDone()) {
    count++;
    it->next();
  }
  CHECK(count == 7);
=======
TEST_CASE("greenHouse::addItem respects maximum capacity of 7 plants") {
  greenHouse gh;

  std::vector<Plant *> ps;
  for (int i = 0; i < 8; i++)
    ps.push_back(new Rose());

  for (int i = 0; i < 7; i++)
    gh.addItem(ps[i]);
  gh.addItem(ps[7]); // should be rejected

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();

  int count = 0;
  while (!it->isDone()) {
    count++;
    it->next();
  }
  CHECK(count == 7);
>>>>>>> Dev

  delete it;
  delete ps[7]; // not added
}

<<<<<<< HEAD
TEST_CASE("greenHouse::removeItem removes specified plant and leaves a hole") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
=======
TEST_CASE("greenHouse::removeItem removes specified plant and leaves a hole") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
>>>>>>> Dev

  gh.addItem(p1, 0, 0);
  gh.addItem(p2, 0, 1);
  gh.addItem(p3, 0, 2);

  gh.removeItem(p2); // hole at (0,1)

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p3);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete p2; // removed, caller deletes
}

<<<<<<< HEAD
TEST_CASE("After remove, addItem(auto) fills earliest hole in row-major") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
  Plant *p4 = new Rose();
=======
TEST_CASE("After remove, addItem(auto) fills earliest hole in row-major") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
  Plant *p4 = new Rose();
>>>>>>> Dev

  gh.addItem(p1, 0, 0);
  gh.addItem(p2, 0, 1);
  gh.addItem(p3, 0, 2);

  gh.removeItem(p2); // hole at (0,1)
  gh.tryAddItem(p4); // should occupy (0,1)

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p4);
  it->next();
  CHECK(it->currItem() == p3);
  it->next();
  CHECK(it->isDone() == true);
  delete it;
  delete p2;
}

<<<<<<< HEAD
TEST_CASE("greenHouse::removeItem handles non-existent plant") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
=======
TEST_CASE("greenHouse::removeItem handles non-existent plant") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
>>>>>>> Dev

  gh.addItem(p1, 0, 0);
  gh.addItem(p2, 0, 1);

  gh.removeItem(p3); // not present

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p2);
  it->next();
  CHECK(it->isDone() == true);
  delete it;
  delete p3;
}

<<<<<<< HEAD
TEST_CASE("greenHouse::CreateIterator returns valid iterator for empty "
          "greenhouse") {
  greenHouse gh;

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
TEST_CASE(
    "greenHouse::CreateIterator returns valid iterator for empty greenhouse") {
  greenHouse gh;

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  CHECK(it->isDone() == true);
  CHECK(it->currItem() == nullptr);

  delete it;
}

<<<<<<< HEAD
TEST_CASE("greenHouse::CreateIterator allows multiple iterations "
          "independently") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
=======
TEST_CASE(
    "greenHouse::CreateIterator allows multiple iterations independently") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
>>>>>>> Dev

  gh.addItem(p1, 0, 0);
  gh.addItem(p2, 2, 2);

<<<<<<< HEAD
  Iterator<Plant *> *it1 = gh.CreateIterator();
  Iterator<Plant *> *it2 = gh.CreateIterator();
=======
  Iterator<Plant *> *it1 = gh.CreateIterator();
  Iterator<Plant *> *it2 = gh.CreateIterator();
>>>>>>> Dev

  it1->first();
  it2->first();

  CHECK(it1->currItem() == p1);
  CHECK(it2->currItem() == p1);

  it1->next();
  CHECK(it1->currItem() == p2);
  CHECK(it2->currItem() == p1);

  delete it1;
  delete it2;
}

<<<<<<< HEAD
TEST_CASE("greenHouse operations sequence: add, remove, add (grid-aware)") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
=======
TEST_CASE("greenHouse operations sequence: add, remove, add (grid-aware)") {
  greenHouse gh;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
>>>>>>> Dev

  gh.addItem(p1, 0, 0);
  gh.addItem(p2, 0, 2);
  gh.removeItem(p1);
  gh.tryAddItem(p3); // should take (0,0)

<<<<<<< HEAD
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
=======
  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();
>>>>>>> Dev

  CHECK(it->currItem() == p3);
  it->next();
  CHECK(it->currItem() == p2);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete p1; // removed
}

<<<<<<< HEAD
TEST_CASE("greenHouse can add plants after removing when at capacity") {
  greenHouse gh;

  std::vector<Plant *> ps;
  for (int i = 0; i < 7; i++) {
    ps.push_back(new Rose());
    gh.addItem(ps[i]);
  }
=======
TEST_CASE("greenHouse can add plants after removing when at capacity") {
  greenHouse gh;

  std::vector<Plant *> ps;
  for (int i = 0; i < 7; i++) {
    ps.push_back(new Rose());
    gh.addItem(ps[i]);
  }
>>>>>>> Dev

  gh.removeItem(ps[3]); // free a slot

<<<<<<< HEAD
  Plant *newPlant = new Rose();
  gh.addItem(newPlant); // should succeed

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();

  int count = 0;
  while (!it->isDone()) {
    count++;
    it->next();
  }
  CHECK(count == 7);
=======
  Plant *newPlant = new Rose();
  gh.addItem(newPlant); // should succeed

  Iterator<Plant *> *it = gh.CreateIterator();
  it->first();

  int count = 0;
  while (!it->isDone()) {
    count++;
    it->next();
  }
  CHECK(count == 7);
>>>>>>> Dev

  delete it;
  delete ps[3];
}
#endif // ENABLE_DOCTESTS
