#include "CustomerAssistant.h"
#include <iostream>
/// @brief Default constructor for CustomerAssistant.
/// Initializes the customer list.
CustomerAssistant::CustomerAssistant()
{
    custList = {};
}
CustomerAssistant::~CustomerAssistant()
{
    for (int i = 0; i < int(custList.size()); i++)
    {
        delete custList[i];
        custList[i] = NULL;
    }
}
/// @brief Destructor for CustomerAssistant.
/// Deletes all dynamically allocated Customer objects in the list.
/// @brief Displays a message indicating that CustomerAssistant does not handle plants.
void CustomerAssistant::care()
{
    cout << "CustomerAssistant: should not be doing anything with plants\n";
}

/// @brief Notifies the assistant to remove a plant from inventory.
/// @param customer Pointer to the Customer initiating the notification.
/// @param plant Pointer to the Plant to be removed.
/// @return True if the plant was successfully removed from inventory.

bool CustomerAssistant::notify(Customer *customer, Plant *plant)
{

    return this->getInventory()->removeItem(plant->getName());
}
/// @brief Receives an update notification from the floor or garden.

void CustomerAssistant::update()
{
    cout << "CustomerAssistant: update() received from floor/garden\n";
}
/// @brief Unit test for basic functionality of CustomerAssistant.


