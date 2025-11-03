/**
 * @file GardenIterator.cpp
 * @brief Implementation of the GardenIterator class.
 */
#include "GardenIterator.h"

//includes used for the unit testing
#include "Garden.h"
#include "Sunny.h"
#include "Shady.h"
#include "PartialSun.h"

/**
 * @brief Constructs an iterator for a vector of Garden pointers.
 * @param gardens A reference to the vector of gardens to iterate over.
 */
GardenIterator::GardenIterator(std::vector<Garden *> &gardens) : currentIndex(0), gardens(gardens){
}

/**
 * @brief Returns the current Garden pointer in the iteration.
 * @return A pointer to the current Garden, or `nullptr` if the iterator is past the end.
 */
Garden *GardenIterator::currItem(){
    if(!isDone()){
        return gardens[currentIndex];
    }else{
        return nullptr;
    }
}

/**
 * @brief Resets the iterator to the first element.
 */
void GardenIterator::first(){
    currentIndex = 0;
}

/**
 * @brief Checks if the iteration is complete.
 * @return `true` if the iterator is past the last element, `false` otherwise.
 */
bool GardenIterator::isDone(){
    return currentIndex >= gardens.size();
}

/**
 * @brief Advances the iterator to the next element.
 * Does nothing if the iterator is already past the end.
 */
void GardenIterator::next(){
    if(!isDone()){
        ++currentIndex;
    }
}

/**
 * @brief Moves the iterator to the previous element.
 * Does nothing if the iterator is at the beginning.
 */
void GardenIterator::prev(){
    if(currentIndex > 0){
        --currentIndex;
    }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("GardenIterator::currItem on empty collection returns nullptr") {
    std::vector<Garden*> gs;
    GardenIterator it(gs);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("GardenIterator::first sets index to 0 and positions at first element when non-empty") {
    std::vector<Garden*> gs;
    gs.push_back(new Sunny());
    gs.push_back(new Shady());

    GardenIterator it(gs);

    it.next(); // move to index 1
    REQUIRE(it.isDone() == false);
    it.first();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == gs[0]);

    for (auto* g : gs) delete g;
}

TEST_CASE("GardenIterator::first on empty keeps iterator done") {
    std::vector<Garden*> gs;
    GardenIterator it(gs);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("GardenIterator::isDone reflects bounds correctly") {
    std::vector<Garden*> gs;
    gs.push_back(new Sunny());

    GardenIterator it(gs);

    it.first();
    CHECK(it.isDone() == false); // at index 0
    it.next();                   // index = 1 == size
    CHECK(it.isDone() == true);

    for (auto* g : gs) delete g;
}

TEST_CASE("GardenIterator::next walks forward and stops at end") {
    std::vector<Garden*> gs;
    gs.push_back(new Sunny());
    gs.push_back(new Shady());
    gs.push_back(new PartialSun());

    GardenIterator it(gs);

    it.first();
    REQUIRE(it.currItem() == gs[0]);

    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == gs[1]);

    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == gs[2]);

    it.next(); // move past end
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    // Calling next() again keeps it done
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    for (auto* g : gs) delete g;
}

TEST_CASE("GardenIterator::prev moves backward; from done goes to last element") {
    std::vector<Garden*> gs;
    gs.push_back(new Sunny());
    gs.push_back(new Shady());

    GardenIterator it(gs);

    // prev at start should not move
    it.first();
    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == gs[0]);

    // Move to done (past end) then prev should go to last valid
    it.next(); // idx 1
    it.next(); // idx 2 -> done
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev(); // idx 1
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == gs[1]);

    it.prev(); // idx 0
    CHECK(it.currItem() == gs[0]);

    for (auto* g : gs) delete g;
}

TEST_CASE("GardenIterator::currItem returns correct pointer across navigation") {
    std::vector<Garden*> gs;
    gs.push_back(new Sunny());
    gs.push_back(new Shady());
    gs.push_back(new PartialSun());

    GardenIterator it(gs);

    it.first();
    CHECK(it.currItem() == gs[0]);
    it.next();
    CHECK(it.currItem() == gs[1]);
    it.prev();
    CHECK(it.currItem() == gs[0]);

    // Move to done and verify nullptr, then step back
    it.next();
    it.next();
    it.next(); // done
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev(); // back to last
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == gs[2]);

    for (auto* g : gs) delete g;
}
#endif
