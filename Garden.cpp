#include "Garden.h"

void Garden::addItem(Garden *item) {
    addGarden(item);
}

Iterator<Garden *> *Garden::CreateIterator() { 
    return new GardenIterator(children); 
}

void Garden::removeItem(Garden *item) {
    removeGarden(item);
}

void Garden::TemplateMethod() {}

void Garden::attach(Staff *staff) {}

void Garden::detach(Staff *staff) {}

void Garden::notify() {}
