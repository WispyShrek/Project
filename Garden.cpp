#include "Garden.h"
#include "PlantCaretaker.h"
#include "Rose.h"
#include "Sunny.h"
#include <algorithm>
#include <iostream>

Garden::Garden()
    : plantCount(0), plants(std::vector<std::vector<Plant *>>(
                         3, std::vector<Plant *>(3, nullptr))) {}
Garden::~Garden() {
  // Clean up all plants (owned while in the grid)
  for (auto &row : plants) {
    for (auto *&p : row) {
      delete p;
      p = nullptr;
    }
  }
}

std::string Garden::print() {
  std::string gardenSprite;
  std::string row;
  std::string plant;
  int fillLength;
  gardenSprite.append("\x1B[38;5;130m");
  for (int r = 0; r < 3; r++) {
    gardenSprite.append(25, '|');
    gardenSprite.append("\n\x1B[38;5;130m");
    row.clear();
    row.append("|||");
    for (int c = 0; c < 3; c++) {
      plant.clear();
      plant.shrink_to_fit();
      if (plants[r][c] == nullptr) {
        row.append("|||||");
      } else {
        plant = plants[r][c]->print();
        if (plant.size() < 28) {
          int pad = (plant.size() - 8) / 2;
          plant.append("\x1B[38;5;130m");
          plant.insert(0, pad, '|');
        }
        row.append(plant);
        fillLength = 6 - plant.length();
        if (fillLength < 0) {
          fillLength = 1;
        }
        row.append(fillLength, '|');
        row.append("\x1B[38;5;130m");
      }
      row.append("|||\x1B[38;5;130m");
    }
    gardenSprite.append(row);
    fillLength = 25 - row.length();
    if (fillLength < 0) {
      fillLength = 0;
    }
    gardenSprite.append(fillLength, '|');
    gardenSprite.append("\n\x1B[38;5;130m");
  }
  gardenSprite.append(25, '|');
  gardenSprite.append("\n\x1B[38;5;130m");

  return gardenSprite;
}

bool Garden::tryAddItem(Plant *item) {
  if (plantCount >= 9) {
    return false;
  }
  // place in first free slot (row-major)
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (plants[r][c] == nullptr) {
        plants[r][c] = item;
        ++plantCount;
        return true;
      }
    }
  }
  // Fallback if grid is unexpectedly full but count < 9
  return false;
}

void Garden::addItem(Plant *item, int row, int col) {
  if (plantCount >= 9) {
    std::cout << "Garden is full, cannot add more plants." << std::endl;
    return;
  }
  if (row < 0 || row >= 3 || col < 0 || col >= 3) {
    std::cout << "Invalid position for plant." << std::endl;
    return;
  }
  if (plants[row][col] != nullptr) {
    std::cout << "Cell already occupied." << std::endl;
    return;
  }
  plants[row][col] = item;
  ++plantCount;
}

Iterator<Plant *> *Garden::CreateIterator() {
  return new PlantIterator(plants);
}

void Garden::removeItem(Plant *item) {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (plants[r][c] == item) {
        plants[r][c] = nullptr;
        --plantCount;
        return;
      }
    }
  }
}

void Garden::applyCare() {}

void Garden::attach(PlantCaretaker *staff) { this->staffList.push_back(staff); }

void Garden::detach(PlantCaretaker *staff) {
  this->staffList.erase(std::find(staffList.begin(), staffList.end(), staff));
}

void Garden::notify() {
  for (auto plantCaretaker : staffList) {
    plantCaretaker->update(this);
  }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Garden::addItem(row,col) places plants; iterator visits in "
          "row-major order") {
  Garden *garden = new Sunny();

  Plant *p0 = new Rose();
  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();

  garden->addItem(p0, 0, 0); // (0,0)
  garden->addItem(p1, 0, 2); // (0,2)
  garden->addItem(p2, 1, 0); // (1,0)
  garden->addItem(p3, 2, 1); // (2,1)

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

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

TEST_CASE("Garden iterator skips null cells") {
  Garden *garden = new Sunny();
  Plant *p1 = new Rose();
  Plant *p2 = new Rose();

  garden->addItem(p1, 0, 0);
  garden->addItem(p2, 2, 2);

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  REQUIRE(it->isDone() == false);
  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p2);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
}

TEST_CASE(
    "Garden::addItem(row,col) rejects invalid indices and occupied cells") {
  Garden *garden = new Sunny();

  Plant *a = new Rose();
  Plant *b = new Rose();
  Plant *c = new Rose();

  garden->addItem(a, 1, 1);
  garden->addItem(b, 1, 1);  // occupied - should not add
  garden->addItem(c, -1, 0); // invalid - should not add

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  REQUIRE(it->isDone() == false);
  CHECK(it->currItem() == a);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete b; // not added
  delete c; // not added
}

TEST_CASE("Garden::addItem(auto) fills first free slot in row-major order") {
  Garden *garden = new Sunny();

  Plant *pA = new Rose();
  Plant *pB = new Rose();
  Plant *pC = new Rose();

  garden->addItem(pA, 0, 0);
  garden->addItem(pB, 0, 1);
  garden->tryAddItem(pC); // should go to (0,2)

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  CHECK(it->currItem() == pA);
  it->next();
  CHECK(it->currItem() == pB);
  it->next();
  CHECK(it->currItem() == pC);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
}

TEST_CASE("Garden::addItem respects maximum capacity of 9 plants") {
  Garden *garden = new Sunny();

  std::vector<Plant *> ps;
  for (int i = 0; i < 10; i++)
    ps.push_back(new Rose());

  for (int i = 0; i < 9; i++)
    garden->tryAddItem(ps[i]);
  garden->tryAddItem(ps[7]); // should be rejected

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  int count = 0;
  while (!it->isDone()) {
    count++;
    it->next();
  }
  CHECK(count == 9);

  delete it;
  delete ps[7]; // not added
}

TEST_CASE("Garden::removeItem removes specified plant and leaves a hole") {
  Garden *garden = new Sunny();

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();

  garden->addItem(p1, 0, 0);
  garden->addItem(p2, 0, 1);
  garden->addItem(p3, 0, 2);

  garden->removeItem(p2); // hole at (0,1)

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p3);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete p2; // removed, caller deletes
}

TEST_CASE("After remove, addItem(auto) fills earliest hole in row-major") {
  Garden *garden = new Sunny();

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();
  Plant *p4 = new Rose();

  garden->addItem(p1, 0, 0);
  garden->addItem(p2, 0, 1);
  garden->addItem(p3, 0, 2);

  garden->removeItem(p2); // hole at (0,1)
  garden->tryAddItem(p4); // should occupy (0,1)

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

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

TEST_CASE("Garden::removeItem handles non-existent plant") {
  Garden *garden = new Sunny();

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();

  garden->addItem(p1, 0, 0);
  garden->addItem(p2, 0, 1);

  garden->removeItem(p3); // not present

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  CHECK(it->currItem() == p1);
  it->next();
  CHECK(it->currItem() == p2);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete p3;
}

TEST_CASE("Garden::CreateIterator returns valid iterator for empty garden") {
  Sunny garden;

  Iterator<Plant *> *it = garden.CreateIterator();
  it->first();

  CHECK(it->isDone() == true);
  CHECK(it->currItem() == nullptr);

  delete it;
}

TEST_CASE("Garden::CreateIterator allows multiple iterations independently") {
  Sunny garden;

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();

  garden.addItem(p1, 0, 0);
  garden.addItem(p2, 2, 2);

  Iterator<Plant *> *it1 = garden.CreateIterator();
  Iterator<Plant *> *it2 = garden.CreateIterator();

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

TEST_CASE("Garden operations sequence: add, remove, add (grid-aware)") {
  Garden *garden = new Sunny();

  Plant *p1 = new Rose();
  Plant *p2 = new Rose();
  Plant *p3 = new Rose();

  garden->addItem(p1, 0, 0);
  garden->addItem(p2, 0, 2);
  garden->removeItem(p1);
  garden->tryAddItem(p3); // should take (0,0)

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  CHECK(it->currItem() == p3);
  it->next();
  CHECK(it->currItem() == p2);
  it->next();
  CHECK(it->isDone() == true);

  delete it;
  delete p1; // removed
}

TEST_CASE("Garden can add plants after removing when at capacity") {
  Garden *garden = new Sunny();

  std::vector<Plant *> ps;
  for (int i = 0; i < 7; i++) {
    ps.push_back(new Rose());
    garden->tryAddItem(ps[i]);
  }

  garden->removeItem(ps[3]); // free a slot

  Plant *newPlant = new Rose();
  garden->tryAddItem(newPlant); // should succeed

  Iterator<Plant *> *it = garden->CreateIterator();
  it->first();

  int count = 0;
  while (!it->isDone()) {
    count++;
    it->next();
  }
  CHECK(count == 7);

  delete it;
  delete ps[3];
}

#endif // ENABLE_DOCTESTS
