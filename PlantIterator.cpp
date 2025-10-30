#include "PlantIterator.h"
#include "Rose.h"

PlantIterator::PlantIterator(std::vector<Plant *> &plants) :currentIndex(0), plants(plants){
}

Plant *PlantIterator::currItem(){
    if(!isDone()){
        return plants[currentIndex];
    }else{
        return nullptr;
    }
}

void PlantIterator::first()
{
    currentIndex = 0;
}

bool PlantIterator::isDone(){
    return currentIndex >= plants.size();
}

void PlantIterator::next() {
  if(!isDone()){
      ++currentIndex;
  }
}

void PlantIterator::prev() {
  if(currentIndex > 0){
      --currentIndex;
  }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("PlantIterator::currItem on empty collection returns nullptr") {
    std::vector<Plant*> plants;
    PlantIterator it(plants);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("PlantIterator::first sets index to 0 and positions at first element when non-empty") {
    std::vector<Plant*> plants;
    plants.push_back(new Rose());
    plants.push_back(new Rose());

    PlantIterator it(plants);

    it.next(); // move to index 1
    REQUIRE(it.isDone() == false);
    it.first();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == plants[0]);

    for (auto* p : plants) delete p;
}

TEST_CASE("PlantIterator::first on empty keeps iterator done") {
    std::vector<Plant*> plants;
    PlantIterator it(plants);

    it.first();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);
}

TEST_CASE("PlantIterator::isDone reflects bounds correctly") {
    std::vector<Plant*> plants;
    plants.push_back(new Rose());

    PlantIterator it(plants);

    it.first();
    CHECK(it.isDone() == false);
    it.next();
    CHECK(it.isDone() == true);

    for (auto* p : plants) delete p;
}

TEST_CASE("PlantIterator::next walks forward and stops at end") {
    std::vector<Plant*> plants;
    plants.push_back(new Rose());
    plants.push_back(new Rose());
    plants.push_back(new Rose());

    PlantIterator it(plants);

    it.first();
    REQUIRE(it.currItem() == plants[0]);
    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == plants[1]);
    it.next();
    REQUIRE(it.isDone() == false);
    CHECK(it.currItem() == plants[2]);
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    // calling next when done should stay done
    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    for (auto* p : plants) delete p;
}

TEST_CASE("PlantIterator::prev moves backward correctly") {
    std::vector<Plant*> plants;
    plants.push_back(new Rose());
    plants.push_back(new Rose());

    PlantIterator it(plants);

    it.first();
    // prev at beginning stays at beginning
    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == plants[0]);

    it.next(); // idx 1
    CHECK(it.currItem() == plants[1]);

    it.prev(); // idx 0
    CHECK(it.currItem() == plants[0]);

    for (auto* p : plants) delete p;
}

TEST_CASE("PlantIterator::prev from done position moves to last element") {
    std::vector<Plant*> plants;
    plants.push_back(new Rose());
    plants.push_back(new Rose());

    PlantIterator it(plants);

    it.first();
    it.next(); // idx 1
    it.next(); // done
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev(); // idx 1
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == plants[1]);

    for (auto* p : plants) delete p;
}

TEST_CASE("PlantIterator works with single plant") {
    std::vector<Plant*> plants;
    plants.push_back(new Rose());

    PlantIterator it(plants);

    it.first();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == plants[0]);

    it.next();
    CHECK(it.isDone() == true);
    CHECK(it.currItem() == nullptr);

    it.prev();
    CHECK(it.isDone() == false);
    CHECK(it.currItem() == plants[0]);

    for (auto* p : plants) delete p;
}

TEST_CASE("PlantIterator returns correct plant type") {
    std::vector<Plant*> plants;
    Rose* rose = new Rose();
    plants.push_back(rose);

    PlantIterator it(plants);

    it.first();
    REQUIRE(it.isDone() == false);
    Plant* current = it.currItem();
    CHECK(current->getName() == "Rose");

    for (auto* p : plants) delete p;
}

#endif // ENABLE_DOCTESTS
