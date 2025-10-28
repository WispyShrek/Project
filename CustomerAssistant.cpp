#include "CustomerAssistant.h"
#include <iostream>

CustomerAssistant::CustomerAssistant() { custList = nullptr; }

void CustomerAssistant::care() {
    std::cout << "CustomerAssistant: assisting with plant care / demos\n";
}

void CustomerAssistant::notify(Customer* customer) {
    custList = customer;
    std::cout << "CustomerAssistant: notify(customer)\n";
}

void CustomerAssistant::update() {
    std::cout << "CustomerAssistant: update() received from floor/controller\n";
}

void CustomerAssistant::update() {
	std::cout << "CustomerAssistant is updated\n";
}