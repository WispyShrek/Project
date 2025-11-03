#include "Garden.h"
#include "PlantCaretaker.h"
#include "Rose.h"
#include "Sunny.h"
#include <algorithm>
#include <iostream>
/**
 * @brief Destructor for the Garden class.
 *
 * Cleans up memory by deleting all Plant objects currently held within the
 * garden's 3x3 grid. This prevents memory leaks when a Garden object is destroyed.
 */
Garden::~Garden(){
    // Clean up all plants (owned while in the grid)
    for (auto& row : plants) {
        for (auto*& p : row) {
            delete p;
            p = nullptr;
        }
    }
}

/**
 * @brief Adds a plant to the first available slot in the garden.
 *
 * This method iterates through the 3x3 grid in row-major order and places the
 * plant in the first empty (nullptr) cell it finds. It respects a capacity limit of 7 plants.
 * @param item A pointer to the Plant object to add. The Garden takes ownership of this pointer.
 */
void Garden::addItem(Plant *item){
    if (plantCount > 6) {
        std::cout << "Garden is full, cannot add more plants." << std::endl;
        return;
    }
    // place in first free slot (row-major)
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (plants[r][c] == nullptr) {
                plants[r][c] = item;
                ++plantCount;
                return;
            }
        }
    }
    // Fallback if grid is unexpectedly full but count <= 6
    std::cout << "Garden has no free slot." << std::endl;
}

/**
 * @brief Adds a plant to a specific position in the garden's grid.
 *
 * This method places a plant at the specified `row` and `col` if the position is
 * within the 3x3 bounds and the cell is currently empty. It respects a capacity limit of 7 plants.
 * @param item A pointer to the Plant object to add. The Garden takes ownership of this pointer.
 * @param row The row index (0-2) where the plant should be placed.
 * @param col The column index (0-2) where the plant should be placed.
 */
void Garden::addItem(Plant *item, int row, int col){
    if (plantCount > 6) {
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

/**
 * @brief Creates an iterator for the plants in the garden.
 *
 * This method is part of the Iterator design pattern. It returns a `PlantIterator`
 * that can be used to traverse the plants in the garden's grid.
 * @return A pointer to a new `Iterator<Plant *>` object. The caller is responsible for deleting it.
 */
Iterator<Plant *> *Garden::CreateIterator(){
    return new PlantIterator(plants);
}

/**
 * @brief Removes a plant from the garden.
 *
 * Searches the grid for the specified plant pointer and sets the cell to nullptr if found. It does not delete the Plant object itself.
 * @param item A pointer to the Plant object to remove.
 */
void Garden::removeItem(Plant *item){
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (plants[r][c] == item) {
                plants[r][c] = nullptr;
                --plantCount;
                return;
            }
        }
    }
}

/**
 * @brief Placeholder for the Template Method design pattern.
 */
void Garden::TemplateMethod() {}

/**
 * @brief Placeholder for applying care to the garden.
 */
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

TEST_CASE("Garden::addItem(row,col) places plants; iterator visits in row-major order") {
    Sunny garden;

    Plant* p0 = new Rose();
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();

    garden.addItem(p0, 0, 0); // (0,0)
    garden.addItem(p1, 0, 2); // (0,2)
    garden.addItem(p2, 1, 0); // (1,0)
    garden.addItem(p3, 2, 1); // (2,1)

    Iterator<Plant*>* it = garden.CreateIterator();
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
    Sunny garden;
    Plant* p1 = new Rose();
    Plant* p2 = new Rose();

    garden.addItem(p1, 0, 0);
    garden.addItem(p2, 2, 2);

    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();

    REQUIRE(it->isDone() == false);
    CHECK(it->currItem() == p1);
    it->next();
    CHECK(it->currItem() == p2);
    it->next();
    CHECK(it->isDone() == true);

    delete it;
}

TEST_CASE("Garden::addItem(row,col) rejects invalid indices and occupied cells") {
    Sunny garden;

    Plant* a = new Rose();
    Plant* b = new Rose();
    Plant* c = new Rose();

    garden.addItem(a, 1, 1);
    garden.addItem(b, 1, 1); // occupied - should not add
    garden.addItem(c, -1, 0); // invalid - should not add

    Iterator<Plant*>* it = garden.CreateIterator();
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
    Sunny garden;

    Plant* pA = new Rose();
    Plant* pB = new Rose();
    Plant* pC = new Rose();

    garden.addItem(pA, 0, 0);
    garden.addItem(pB, 0, 1);
    garden.addItem(pC); // should go to (0,2)

    Iterator<Plant*>* it = garden.CreateIterator();
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

TEST_CASE("Garden::addItem respects maximum capacity of 7 plants") {
    Sunny garden;

    std::vector<Plant*> ps;
    for (int i = 0; i < 8; i++) ps.push_back(new Rose());

    for (int i = 0; i < 7; i++) garden.addItem(ps[i]);
    garden.addItem(ps[7]); // should be rejected

    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();

    int count = 0;
    while (!it->isDone()) {
        count++;
        it->next();
    }
    CHECK(count == 7);

    delete it;
    delete ps[7]; // not added
}

TEST_CASE("Garden::removeItem removes specified plant and leaves a hole") {
    Sunny garden;

    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();

    garden.addItem(p1, 0, 0);
    garden.addItem(p2, 0, 1);
    garden.addItem(p3, 0, 2);

    garden.removeItem(p2); // hole at (0,1)

    Iterator<Plant*>* it = garden.CreateIterator();
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
    Sunny garden;

    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();
    Plant* p4 = new Rose();

    garden.addItem(p1, 0, 0);
    garden.addItem(p2, 0, 1);
    garden.addItem(p3, 0, 2);

    garden.removeItem(p2); // hole at (0,1)
    garden.addItem(p4);    // should occupy (0,1)

    Iterator<Plant*>* it = garden.CreateIterator();
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
    Sunny garden;

    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();

    garden.addItem(p1, 0, 0);
    garden.addItem(p2, 0, 1);

    garden.removeItem(p3); // not present

    Iterator<Plant*>* it = garden.CreateIterator();
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

    Iterator<Plant*>* it = garden.CreateIterator();
    it->first();

    CHECK(it->isDone() == true);
    CHECK(it->currItem() == nullptr);

    delete it;
}

TEST_CASE("Garden::CreateIterator allows multiple iterations independently") {
    Sunny garden;

    Plant* p1 = new Rose();
    Plant* p2 = new Rose();

    garden.addItem(p1, 0, 0);
    garden.addItem(p2, 2, 2);

    Iterator<Plant*>* it1 = garden.CreateIterator();
    Iterator<Plant*>* it2 = garden.CreateIterator();

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
    Sunny garden;

    Plant* p1 = new Rose();
    Plant* p2 = new Rose();
    Plant* p3 = new Rose();

    garden.addItem(p1, 0, 0);
    garden.addItem(p2, 0, 2);
    garden.removeItem(p1);
    garden.addItem(p3); // should take (0,0)

    Iterator<Plant*>* it = garden.CreateIterator();
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
    Sunny garden;

    std::vector<Plant*> ps;
    for (int i = 0; i < 7; i++) {
        ps.push_back(new Rose());
        garden.addItem(ps[i]);
    }

    garden.removeItem(ps[3]); // free a slot

    Plant* newPlant = new Rose();
    garden.addItem(newPlant); // should succeed

    Iterator<Plant*>* it = garden.CreateIterator();
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
