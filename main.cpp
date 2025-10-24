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
#include "GardenIterator.h"

int main() {
    using std::cout;
    using std::endl;

    cout << "\n=== Testing Garden Iterator ===\n" << endl;
    Garden* garden = new Garden();
    
    // Add plants
    garden->addItem(new Rose());
    garden->addItem(new Tulip());
    garden->addItem(new Lavender());
    garden->addItem(new Lily());
    
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
    
    // Move to end
    gardenIt->next();
    gardenIt->next();
    gardenIt->next();
    gardenIt->next();
    
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
    return 0;
}
