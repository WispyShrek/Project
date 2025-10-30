#include "greenHouse.h"
#include "GreenhouseController.h"
#include "Sunny.h"
#include "Shady.h"
#include "PartialSun.h"

void greenHouse::powerSystem() {
    GreenhouseController controller;
    controller.flipUp();     // e.g. [Sprinkler] ON
    controller.flipDown();   // e.g. [Sprinkler] OFF
}

Iterator<Garden *> *greenHouse::CreateIterator(){
    return new GardenIterator(gardens);
}

void greenHouse::addItem(Garden *item){
    gardens.push_back(item);
}

void greenHouse::removeItem(Garden *item){
    for(auto it = gardens.begin(); it != gardens.end(); ++it){
        if(*it == item){
            gardens.erase(it);
            return;
        }
    }
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("greenHouse::addItem adds gardens to greenhouse") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Shady();
    Garden* g3 = new PartialSun();
    
    gh.addItem(g1);
    gh.addItem(g2);
    gh.addItem(g3);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == false);
    CHECK(it->currItem() == g1);
    it->next();
    CHECK(it->currItem() == g2);
    it->next();
    CHECK(it->currItem() == g3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    for(auto* g : std::vector<Garden*>{g1, g2, g3}) delete g;
}

TEST_CASE("greenHouse::addItem handles multiple gardens of same type") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Sunny();
    Garden* g3 = new Sunny();
    
    gh.addItem(g1);
    gh.addItem(g2);
    gh.addItem(g3);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    int count = 0;
    while(!it->isDone()){
        count++;
        it->next();
    }
    
    CHECK(count == 3);
    
    delete it;
    for(auto* g : std::vector<Garden*>{g1, g2, g3}) delete g;
}

TEST_CASE("greenHouse::removeItem removes first occurrence of garden") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Shady();
    Garden* g3 = new PartialSun();
    
    gh.addItem(g1);
    gh.addItem(g2);
    gh.addItem(g3);
    
    gh.removeItem(g2);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == g1);
    it->next();
    CHECK(it->currItem() == g3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete g2; // Manually delete removed garden
    for(auto* g : std::vector<Garden*>{g1, g3}) delete g;
}

TEST_CASE("greenHouse::removeItem handles non-existent garden") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Shady();
    Garden* g3 = new PartialSun();
    
    gh.addItem(g1);
    gh.addItem(g2);
    
    gh.removeItem(g3); // g3 was never added
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == g1);
    it->next();
    CHECK(it->currItem() == g2);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete g3;
    for(auto* g : std::vector<Garden*>{g1, g2}) delete g;
}

TEST_CASE("greenHouse::removeItem on empty greenhouse does nothing") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    
    gh.removeItem(g1);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == true);
    
    delete it;
    delete g1;
}

TEST_CASE("greenHouse::removeItem removes only first duplicate") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Sunny();
    Garden* g3 = new Sunny();
    
    gh.addItem(g1);
    gh.addItem(g2);
    gh.addItem(g3);
    
    gh.removeItem(g1);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == g2);
    it->next();
    CHECK(it->currItem() == g3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete g1;
    for(auto* g : std::vector<Garden*>{g2, g3}) delete g;
}

TEST_CASE("greenHouse::CreateIterator returns valid iterator for empty greenhouse") {
    greenHouse gh;
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->isDone() == true);
    CHECK(it->currItem() == nullptr);
    
    delete it;
}

TEST_CASE("greenHouse::CreateIterator allows multiple iterations") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Shady();
    
    gh.addItem(g1);
    gh.addItem(g2);
    
    Iterator<Garden*>* it1 = gh.CreateIterator();
    Iterator<Garden*>* it2 = gh.CreateIterator();
    
    it1->first();
    it2->first();
    
    CHECK(it1->currItem() == g1);
    CHECK(it2->currItem() == g1);
    
    it1->next();
    CHECK(it1->currItem() == g2);
    CHECK(it2->currItem() == g1);
    
    delete it1;
    delete it2;
    for(auto* g : std::vector<Garden*>{g1, g2}) delete g;
}

TEST_CASE("greenHouse operations sequence: add, remove, add") {
    greenHouse gh;
    
    Garden* g1 = new Sunny();
    Garden* g2 = new Shady();
    Garden* g3 = new PartialSun();
    
    gh.addItem(g1);
    gh.addItem(g2);
    gh.removeItem(g1);
    gh.addItem(g3);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    CHECK(it->currItem() == g2);
    it->next();
    CHECK(it->currItem() == g3);
    it->next();
    CHECK(it->isDone() == true);
    
    delete it;
    delete g1; // Manually delete removed garden
    for(auto* g : std::vector<Garden*>{g2, g3}) delete g;
}

TEST_CASE("greenHouse can handle mixed garden types") {
    greenHouse gh;
    
    Garden* sunny = new Sunny();
    Garden* shady = new Shady();
    Garden* partial = new PartialSun();
    
    gh.addItem(sunny);
    gh.addItem(shady);
    gh.addItem(partial);
    
    Iterator<Garden*>* it = gh.CreateIterator();
    it->first();
    
    int count = 0;
    while(!it->isDone()){
        CHECK(it->currItem() != nullptr);
        count++;
        it->next();
    }
    
    CHECK(count == 3);
    
    delete it;
    for(auto* g : std::vector<Garden*>{sunny, shady, partial}) delete g;
}

#endif // ENABLE_DOCTESTS
