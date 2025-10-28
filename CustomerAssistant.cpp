#include "CustomerAssistant.h"
#include <iostream>

CustomerAssistant::CustomerAssistant()
{
    custList = {};
}
CustomerAssistant::~CustomerAssistant() {
    for(int i=0; i<custList.size(); i++) {
        delete custList[i];
        custList[i] = NULL;
    }
}
void CustomerAssistant::care()
{
    cout << "CustomerAssistant: should not be doing anything with plants\n";
}

void CustomerAssistant::notify(Customer *customer)
{
    
    cout << "CustomerAssistant: notifying customer. Customer cart has changed:\n" << customer->cartToString() << "\n";
}

void CustomerAssistant::update()
{

    cout << "CustomerAssistant: update() received from floor/garden\n";
}
