#include <iostream>
#include <vector>
#include "Garden.h"
#include "Plant.h"
#include "Rose.h"
#include "Tulip.h"
#include "Lavender.h"
#include "Lily.h"
#include "Inventory.h"
#include "Iterator.h"
#include "PlantIterator.h"
#include "GardenIterator.h"
#include "GreenhouseIterator.h"
#include "LilyCreator.h"
#include "RoseCreator.h"
#include "TulipCreator.h"
#include "LavenderCreator.h"
#include "greenHouse.h"
#include "GreenhouseController.h"
#include "PlantCaretakerCreator.h"
#include "CustomerAssistantCreator.h"
#include "Sunny.h"
#include "Nursery.h"
#include "PlantCaretaker.h"
#include "CustomerAssistant.h"
#include "CareStrategy.h"
#include "SunnyCare.h"
#include "ShadyCare.h"
#include "PartialSunCare.h"
#include "Plant.h"
#include "EFT.h"
#include "Card.h"
#include "Cash.h"
#include "PaymentStrategy.h"
#include "Transaction.h"
#include "PlantCaretaker.h"
#include "Caretaker.h"
#include "PlantMemento.h"
#include "FussyCust.h"

int main() {
    using std::cout;
    using std::endl;

    // === Grid-based iterator tests (Garden + PlantIterator) ===
    cout << "\n=== Grid-based Garden/PlantIterator tests ===\n";
    Garden* g = new Sunny();

    Plant* g_p1 = new Rose();
    Plant* g_p2 = new Lily();
    Plant* g_p3 = new Lavender();
    Plant* g_p4 = new Tulip();

    // Place at positions, then auto-fill first free
    g->addItem(g_p1, 0, 0);
    g->addItem(g_p2, 0, 2);
    g->addItem(g_p3);            // should take (0,1)
    g->addItem(g_p4, 2, 2);

    Iterator<Plant*>* git = g->CreateIterator();
    git->first();
    cout << "Garden iteration (row-major, skipping nulls):\n";
    while (!git->isDone()) {
        if (auto* p = git->currItem()) p->print();
        git->next();
    }

    cout << "\nGarden removeItem (creates hole) and auto-fill earliest hole:\n";
    g->removeItem(g_p3);         // hole at (0,1)
    Plant* g_p5 = new Rose();
    g->addItem(g_p5);            // fills (0,1)
    git->first();
    while (!git->isDone()) {
        if (auto* p = git->currItem()) p->print();
        git->next();
    }

    cout << "\nGarden PlantIterator prev() from done goes to last:\n";
    git->first();
    while (!git->isDone()) git->next();
    git->prev();
    if (auto* p = git->currItem()) p->print();

    delete git; // Garden owns remaining plants
    delete g_p3; // removed earlier
    delete g;

    // === Grid-based iterator tests (greenHouse + PlantIterator) ===
    cout << "\n=== Grid-based greenHouse/PlantIterator tests ===\n";
    greenHouse gh;

    // Explicit placement plus auto-fill, same logic as Garden
    Plant* h1 = new Rose();
    Plant* h2 = new Tulip();
    Plant* h3 = new Lavender();
    Plant* h4 = new Lily();

    gh.addItem(h1, 0, 0);   // place at (0,0)
    gh.addItem(h2, 0, 2);   // place at (0,2)
    gh.addItem(h3);         // auto-fill -> (0,1)
    gh.addItem(h4, 2, 2);   // place at (2,2)

    Iterator<Plant*>* hit = gh.CreateIterator();
    hit->first();
    cout << "greenHouse iteration (row-major, skipping nulls):\n";
    while (!hit->isDone()) {
        if (auto* p = hit->currItem()) p->print();
        hit->next();
    }

    cout << "\ngreenHouse removeItem (skip hole), then prev() from done:\n";
    gh.removeItem(h3); // create hole at (0,1)
    hit->first();
    while (!hit->isDone()) {
        if (auto* p = hit->currItem()) p->print();
        hit->next();
    }
    hit->prev(); // from done -> last non-null
    if (auto* p = hit->currItem()) p->print();

    // Capacity quick check: fill to 7 and ensure we don't exceed
    {
        // Currently we have h1 at (0,0), h2 at (0,2), h4 at (2,2)
        // Add 4 more
        std::vector<Plant*> extras;
        for (int i = 0; i < 4; ++i) {
            auto* np = new Rose();
            extras.push_back(np);
            gh.addItem(np);
        }
        // Attempt 8th (should be rejected; message printed)
        Plant* overflow = new Rose();
        gh.addItem(overflow);
        // Clean up overflow (not added, so not owned by gh)
        delete overflow;

        // Clean up: remove everything we manually own from gh before scope ends
        for (auto* p : extras) gh.removeItem(p);
        for (auto* p : extras) delete p;
    }

    delete hit;
    // Remove and delete the ones we added that were removed from gh
    gh.removeItem(h1); delete h1;
    gh.removeItem(h2); delete h2;
    gh.removeItem(h4); delete h4;

    // ...existing demo/tests...
    cout << "\n=== Testing Garden Iterator ===\n" << endl;
    Garden* garden = new Sunny();
    
    // Add plants
    garden->addItem(new Rose());
    garden->addItem(new Tulip());
    garden->addItem(new Lavender());
    garden->addItem(new Lily());
    garden->addItem(new Rose());
    garden->addItem(new Tulip());

    std::cout << "Added 6 plants to the garden." << std::endl;

    
    Iterator<Plant*>* gardenIt = garden->CreateIterator();
    
    cout << "Testing first() and currItem():" << endl;
    gardenIt->first();
    if (Plant* p = gardenIt->currItem()) {
        p->print();
    }
    
    cout << "\nTesting next() and currItem():" << endl;
    gardenIt->next();
    if (Plant* p = gardenIt->currItem()) {
        p->print();
    }
    
    cout << "\nTesting prev() and currItem():" << endl;
    gardenIt->prev();
    if (Plant* p = gardenIt->currItem()) {
        p->print();
    }
    
    cout << "\nTesting isDone() at valid position:" << endl;
    cout << "isDone: " << (gardenIt->isDone() ? "true" : "false") << endl;
    
    while (!gardenIt->isDone()) {
        gardenIt->next();
    }

    cout << "\nTesting isDone() after moving past end:" << endl;
    cout << "isDone: " << (gardenIt->isDone() ? "true" : "false") << endl;
    
    delete gardenIt;
    
    cout << "\n=== Testing Inventory Iterator ===\n" << endl;
    Inventory inventory;
    
    inventory.addItem("Plant Food");
    inventory.addItem("Watering Can");
    inventory.addItem("Garden Shears");
    
    Iterator<std::string>* invIt = inventory.CreateIterator();
    
    cout << "Testing first() and currItem():" << endl;
    invIt->first();
    cout << invIt->currItem() << endl;
    
    cout << "\nTesting next() and currItem():" << endl;
    invIt->next();
    cout << invIt->currItem() << endl;
    
    cout << "\nTesting prev() and currItem():" << endl;
    invIt->prev();
    cout << invIt->currItem() << endl;
    
    cout << "\nTesting isDone() at valid position:" << endl;
    cout << "isDone: " << (invIt->isDone() ? "true" : "false") << endl;
    
    // Move to end
    invIt->next();
    invIt->next();
    invIt->next();
    
    cout << "\nTesting isDone() after moving past end:" << endl;
    cout << "isDone: " << (invIt->isDone() ? "true" : "false") << endl;
    
    delete invIt;
    delete garden;
    
    cout << "\nDone." << endl;

    // ===== Test Lily =====
    {
        std::cout << "\n=== LilyCreator ===\n";
        LilyCreator maker;
        Plant* a = maker.createPlant();                         // Factory Method
        std::cout << "created: " << a->getState() << "\n";

        Plant* b = a->clone();                                  // Prototype
        std::cout << "cloned : " << b->getState() << "\n";

    }

    // ===== Test Rose =====
    {
        std::cout << "\n=== RoseCreator ===\n";
        RoseCreator maker;
        Plant* a = maker.createPlant();
        std::cout << "created: " << a->getState() << "\n";

        Plant* b = a->clone();
        std::cout << "cloned : " << b->getState() << "\n";

    }

    // ===== Test Tulip =====
    {
        std::cout << "\n=== TulipCreator ===\n";
        TulipCreator maker;
        Plant* a = maker.createPlant();
        std::cout << "created: " << a->getState() << "\n";

        Plant* b = a->clone();
        std::cout << "cloned : " << b->getState() << "\n";

    }

    // ===== Test Lavender =====
    {
        std::cout << "\n=== LavenderCreator ===\n";
        LavenderCreator maker;
        Plant* a = maker.createPlant();
        std::cout << "created: " << a->getState() << "\n";

        Plant* b = a->clone();
        std::cout << "cloned : " << b->getState() << "\n";

    }

    std::cout << "\nAll factory tests done.\n";

    Lily plant;  // starts in Sprout (from Plant::Plant())
    plant.print();

    std::cout << "start: " << plant.getState() << "\n";        // expect: Sprout
    plant.Plant::print();

    plant.applyCare();                                       
    std::cout << "after care: " << plant.getState() << "\n"; 
    plant.Plant::print();
    
    plant.applyCare();                                         // Flowering -> Mature
    std::cout << "after more care: " << plant.getState() << "\n"; // expect: Mature
    plant.Plant::print();

    plant.applyCare();                                      
    std::cout << "after care to Mature: " << plant.getState() << "\n";
    plant.Plant::print();

    std::cout << "All state tests done" << std::endl;



    std::cout << "== Direct controller test ==\n";
    {
        GreenhouseController ctl;   // defaults to SprinklersOn/Off

        std::cout << "Flip up:\n";
        ctl.flipUpSprinklers();               // expect: [Sprinkler] ON

        std::cout << "Flip down:\n";
        ctl.flipDownSprinklers();             // expect: [Sprinkler] OFF

        std::cout << "Flip up x2 then down:\n";
        ctl.flipUpSprinklers();               // [Sprinkler] ON
        ctl.flipUpSprinklers();               // [Sprinkler] ON (again)
        ctl.flipDownSprinklers();             // [Sprinkler] OFF

        
    } 
    std::cout << "\n== greenHouse::powerSystem() test ==\n";
    {
        greenHouse gh;
        gh.powerSystem();           // internally creates a controller and flips up/down
    }

    std::cout << "\nAll tests done.\n";


    std::cout << "== Staff factory test ==\n";

    PlantCaretakerCreator pcc;
    CustomerAssistantCreator cac;

    Staff* a = pcc.createStaff();    // Factory Method
    Staff* b = cac.createStaff();
    Customer* cust1 = new FussyCust();/*
    a->care();    a->update();    a->notify(cust1);
    b->care();    b->update();    b->notify(cust1);
*/  
    delete cust1;
    delete b; 
    delete a;

    std::cout << "Done.\n";
    // =========Singleton tests ==========

    std::cout << "=== Singleton/Nursery ===";

    Nursery& nursery1 = Nursery::instance();
    Nursery& nursery2 = Nursery::instance();

    std::cout << "Checking if both references are the same instance...\n";
    if (&nursery1 == &nursery2)
        std::cout << "PASS: Only one instance exists.\n";
    else
        std::cout << "FAIL: Multiple instances detected!\n";

    PlantCaretaker* caretaker = new PlantCaretaker();
    CustomerAssistant* assistant = new CustomerAssistant();

    nursery1.addStaff(caretaker);
    nursery1.addStaff(assistant);

    std::cout << "Added staff.\n";

    nursery1.addStaff(caretaker);


    // Add gardens
    Garden* garden1 = new Sunny();
    Garden* garden2 = new Sunny();
    nursery1.addGarden(garden1);
    nursery1.addGarden(garden2);

    std::cout << "Added gardens.\n";

    // Test remove
    nursery1.removeStaff(caretaker);
    nursery1.removeGarden(garden1);

    std::cout << "Removed one staff and one garden.\n";

    for (int i = 0; i < 5; ++i) {
        PlantCaretaker* temp = new PlantCaretaker();
        nursery1.addStaff(temp);
        nursery1.removeStaff(temp);
        delete temp; // avoid memory leak
    }
    std::cout << "Stress test completed.\n";

    std::cout << "Staff count: " << nursery1.getStaffCount() << "\n";
    std::cout << "Garden count: " << nursery1.getGardenCount() << "\n";

    nursery1.removeStaff(assistant);
    nursery1.removeGarden(garden2);
    delete caretaker;
    delete assistant;
    delete garden1;
    delete garden2;

    std::cout << "Final cleanup done.\n";


    // =========== Strategy Testing ===============
    std::cout << "=== Strategy/Plant Care ===\n";

    std::vector<Plant*> plants;
    plants.push_back(new Lavender());

    std::cout << "\nAssigning care strategies...\n";
    plants[0]->setCareStrategy(new SunnyCare());
    plants[0]->applyCare();

    std::cout << "\nSwitching to ShadyCare...\n";
    plants[0]->setCareStrategy(new ShadyCare());
    plants[0]->applyCare();

    std::cout << "\nSwitching to PartialSunCare...\n";
    plants[0]->setCareStrategy(new PartialSunCare());
    plants[0]->applyCare();

    std::cout << "\n=== Stress Test: Swapping Strategies Dynamically ===\n";
    for (int i = 0; i < 5; ++i) {
        CareStrategy* s;
        if (i % 3 == 0)
            s = new SunnyCare();
        else if (i % 3 == 1)
            s = new ShadyCare();
        else
            s = new PartialSunCare();

        plants[0]->setCareStrategy(s);
        plants[0]->applyCare();
    }

    std::cout << "\nCloning the Lavender plant...\n";
    Plant* clone = plants[0]->clone();
    clone->print();

    for (auto p : plants)
        delete p;
    delete clone;


    //===testing PaymentStrategy =====
    Transaction transaction;
    Cash cashPayment;
    Card cardPayment;
    EFT eftPayment;

    std::cout << "Setting payment strategy to CASH..." << std::endl;
    transaction.setPaymentStrategy(&cashPayment);
    transaction.pay();  // Expected: Pay with cash.

    std::cout << "\n--------------------------------------------\n" << std::endl;

    std::cout << "Setting payment strategy to CARD..." << std::endl;
    transaction.setPaymentStrategy(&cardPayment);
    transaction.pay();  // Expected: Pay with card.

    std::cout << "\n--------------------------------------------\n" << std::endl;

    std::cout << "Setting payment strategy to EFT..." << std::endl;
    transaction.setPaymentStrategy(&eftPayment);
    transaction.pay();  // Expected: Pay via EFT.

    std::cout << "\n--------------------------------------------\n" << std::endl;

    std::cout << "Testing transaction without a strategy..." << std::endl;
    Transaction emptyTransaction;
    emptyTransaction.pay();  // Expected: No payment strategy set :(


    std::cout << "\n Strategy pattern test complete.\n";

    //===memento testing ===
    
    Rose myRose;          
    Caretaker plantHistory;

    myRose.setState(new Sprout());
    std::cout << "Step 1: Initial state set to: " << myRose.getState() << std::endl;

    std::cout << "Step 2: Saving state (" << myRose.getState() << ") to Caretaker..." << std::endl;
    plantHistory.setPlantMemento(myRose.createPlantMemento());
    std::cout << "   ...State saved. ✅\n" << std::endl;

    std::cout << "Step 3: Plant is growing... changing state." << std::endl;
    myRose.setState(new Flowering());
    std::cout << "   Current plant state is now: " << myRose.getState() << std::endl;

    std::cout << "Step 4: Plant continues growing..." << std::endl;
    myRose.setState(new Mature());
    std::cout << "   Current plant state is now: " << myRose.getState() << "\n" << std::endl;

    std::cout << "Step 5: A customer wants to see the saved state. Restoring..." << std::endl;
    myRose.setPlantMemento(plantHistory.getPlantMemento());
    std::cout << "   ...State restored from Caretaker.\n" << std::endl;

    std::cout << "=== Verification ===" << std::endl;
    std::cout << "Final plant state is: " << myRose.getState() << std::endl;
    
    if (myRose.getState() == "Sprout") {
        std::cout << "PASS: State successfully restored to 'Sprout'. ✅\n";
    } else {
        std::cout << "FAIL: State was not restored. Expected 'Sprout' but got '" 
                  << myRose.getState() << "'. ❌\n";
    }

    std::cout << "\nTest complete. \n" << std::endl;

    return 0;
}
