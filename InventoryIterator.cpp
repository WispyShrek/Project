/**
 * @file InventoryIterator.cpp
 * @brief Implementation of the InventoryIterator class.
 */
#include "InventoryIterator.h"

/**
 * @brief Constructs an iterator for a vector of strings.
 * @param items A reference to the vector of strings to iterate over.
 */
InventoryIterator::InventoryIterator(std::vector<std::string> & items) : currentIndex(0), items(items){
}

/**
 * @brief Returns the current item string in the iteration.
 * @return The current item as a string, or an empty string if the iterator is past the end.
 */
std::string InventoryIterator::currItem()
{
    if(!isDone()){
        return items[currentIndex];
    }else{
        std::cout << "No current item, iterator is done." << std::endl;
        return std::string();
    }
}

/**
 * @brief Resets the iterator to the first element.
 */
void InventoryIterator::first(){
    currentIndex = 0;
}

/**
 * @brief Checks if the iteration is complete.
 * @return `true` if the iterator is past the last element, `false` otherwise.
 */
bool InventoryIterator::isDone(){
    return currentIndex >= items.size();
}

/**
 * @brief Advances the iterator to the next element.
 * Does nothing if the iterator is already past the end.
 */
void InventoryIterator::next(){
    if(!isDone()){
        currentIndex++;
    }
}

/**
 * @brief Moves the iterator to the previous element.
 * Does nothing if the iterator is at the beginning.
 */
void InventoryIterator::prev(){
    if(currentIndex > 0){
        currentIndex--;
    }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("InventoryIterator::currItem on empty collection returns empty string") {
    std::vector<std::string> items;
    InventoryIterator it(items);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == std::string());
}

TEST_CASE("InventoryIterator::first sets index to 0 and positions at first element when non-empty") {
    std::vector<std::string> items;
    items.push_back("seeds");
    items.push_back("fertilizer");

    InventoryIterator it(items);

    it.next(); // move to index 1
    REQUIRE(it.isDone() == false);
    it.first();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == "seeds");
}

TEST_CASE("InventoryIterator::first on empty keeps iterator done") {
    std::vector<std::string> items;
    InventoryIterator it(items);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == std::string());
}

TEST_CASE("InventoryIterator::isDone reflects bounds correctly") {
    std::vector<std::string> items;
    items.push_back("seeds");

    InventoryIterator it(items);

    it.first();
    CHECK(it.isDone() == false);
    it.next();
    CHECK(it.isDone() == true);
}

TEST_CASE("InventoryIterator::next walks forward and stops at end") {
    std::vector<std::string> items;
    items.push_back("seeds");
    items.push_back("fertilizer");
    items.push_back("water");

    InventoryIterator it(items);

    it.first();
    REQUIRE(it.currItem() == "seeds");
    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == "fertilizer");
    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == "water");
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == std::string());

    // calling next when done should stay done
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == std::string());
}

TEST_CASE("InventoryIterator::prev moves backward correctly") {
    std::vector<std::string> items;
    items.push_back("seeds");
    items.push_back("fertilizer");

    InventoryIterator it(items);

    it.first();
    // prev at beginning stays at beginning
    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == "seeds");

    it.next(); // idx 1
    CHECK(it.currItem() == "fertilizer");

    it.prev(); // idx 0
    CHECK(it.currItem() == "seeds");
}

TEST_CASE("InventoryIterator::prev from done position moves to last element") {
    std::vector<std::string> items;
    items.push_back("seeds");
    items.push_back("fertilizer");

    InventoryIterator it(items);

    it.first();
    it.next(); // idx 1
    it.next(); // done
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == std::string());

    it.prev(); // idx 1
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == "fertilizer");
}

TEST_CASE("InventoryIterator works with single item") {
    std::vector<std::string> items;
    items.push_back("seeds");

    InventoryIterator it(items);

    it.first();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == "seeds");

    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == std::string());

    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == "seeds");
}

#endif // ENABLE_DOCTESTS
