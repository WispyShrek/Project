#include "PlantCaretaker.h"
#include <iostream>

PlantCaretaker::PlantCaretaker() { custList = nullptr; }

void PlantCaretaker::care() {
    std::cout << "PlantCaretaker: tending plants (watering/pruning)\n";
}

void PlantCaretaker::update() {
    std::cout << "PlantCaretaker: update() received from floor/controller\n";
}

void PlantCaretaker::notify(Customer* customer) {
    custList = customer; 
    std::cout << "PlantCaretaker: notify(customer)\n";
}
