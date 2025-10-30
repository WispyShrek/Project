#include "GreenhouseIterator.h"
#include "greenHouse.h"

GreenhouseIterator::GreenhouseIterator(std::vector<greenHouse *> &greenHouses): currentIndex(0), greenHouses(greenHouses){
}

greenHouse *GreenhouseIterator::currItem(){
    if(!isDone()){
        return greenHouses[currentIndex];
    }else{
        return nullptr;
    }
}

void GreenhouseIterator::first(){
    currentIndex = 0;
}

bool GreenhouseIterator::isDone(){
    return currentIndex >= greenHouses.size();
}

void GreenhouseIterator::next(){
    if(!isDone()){
        ++currentIndex;
    }
}

void GreenhouseIterator::prev(){
    if(currentIndex > 0){
        --currentIndex;
    }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("GreenhouseIterator::currItem on empty collection returns nullptr") {
    std::vector<greenHouse*> greenHouses;
    GreenhouseIterator it(greenHouses);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("GreenhouseIterator::first sets index to 0 and positions at first element when non-empty") {
    std::vector<greenHouse*> greenHouses;
    greenHouses.push_back(new greenHouse());
    greenHouses.push_back(new greenHouse());

    GreenhouseIterator it(greenHouses);

    it.next(); // move to index 1
    REQUIRE(it.isDone() == false);
    it.first();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[0]);

    for (auto* gh : greenHouses) delete gh;
}

TEST_CASE("GreenhouseIterator::first on empty keeps iterator done") {
    std::vector<greenHouse*> greenHouses;
    GreenhouseIterator it(greenHouses);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("GreenhouseIterator::isDone reflects bounds correctly") {
    std::vector<greenHouse*> greenHouses;
    greenHouses.push_back(new greenHouse());

    GreenhouseIterator it(greenHouses);

    it.first();
    CHECK(it.isDone() == false);
    it.next();
    CHECK(it.isDone() == true);

    for (auto* gh : greenHouses) delete gh;
}

TEST_CASE("GreenhouseIterator::next walks forward and stops at end") {
    std::vector<greenHouse*> greenHouses;
    greenHouses.push_back(new greenHouse());
    greenHouses.push_back(new greenHouse());
    greenHouses.push_back(new greenHouse());

    GreenhouseIterator it(greenHouses);

    it.first();
    REQUIRE(it.currItem() == greenHouses[0]);
    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[1]);
    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[2]);
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    // calling next when done should stay done
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    for (auto* gh : greenHouses) delete gh;
}

TEST_CASE("GreenhouseIterator::prev moves backward correctly") {
    std::vector<greenHouse*> greenHouses;
    greenHouses.push_back(new greenHouse());
    greenHouses.push_back(new greenHouse());

    GreenhouseIterator it(greenHouses);

    it.first();
    // prev at beginning stays at beginning
    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[0]);

    it.next(); // idx 1
    CHECK(it.currItem() == greenHouses[1]);

    it.prev(); // idx 0
    CHECK(it.currItem() == greenHouses[0]);

    for (auto* gh : greenHouses) delete gh;
}

TEST_CASE("GreenhouseIterator::prev from done position moves to last element") {
    std::vector<greenHouse*> greenHouses;
    greenHouses.push_back(new greenHouse());
    greenHouses.push_back(new greenHouse());

    GreenhouseIterator it(greenHouses);

    it.first();
    it.next(); // idx 1
    it.next(); // done
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev(); // idx 1
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[1]);

    for (auto* gh : greenHouses) delete gh;
}

TEST_CASE("GreenhouseIterator works with single greenhouse") {
    std::vector<greenHouse*> greenHouses;
    greenHouses.push_back(new greenHouse());

    GreenhouseIterator it(greenHouses);

    it.first();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[0]);

    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == greenHouses[0]);

    for (auto* gh : greenHouses) delete gh;
}

#endif // ENABLE_DOCTESTS
