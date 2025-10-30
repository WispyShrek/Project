#include "Nursery.h"

/**
 * @brief Protected constructor to prevent direct instantiation.
 *
 * As part of the Singleton pattern, the constructor is not public.
 */
Nursery::Nursery() {
}

/**
 * @brief Protected destructor.
 *
 * The destructor is responsible for cleaning up the Nursery instance when the
 * program terminates. It does not deallocate the memory for the gardens and
 * staff it contains, as it does not own these objects.
 */
Nursery::~Nursery() {
}

/**
 * @brief Returns the single, static instance of the Nursery class.
 *
 * This function uses a static local variable to ensure that the instance is
 * created only once, the first time this function is called.
 * @return A reference to the singleton instance.
 */
Nursery& Nursery::instance() {
    static Nursery uniqueInstance;
    return uniqueInstance;
}

/**
 * @brief Adds a new garden to the list of gardens managed by the nursery.
 * @param newGarden A pointer to the Garden object to be added.
 */
void Nursery::addGarden(Garden* newGarden) {
    if(newGarden)
        gardens.push_back(newGarden);
}

/**
 * @brief Adds a new staff member to the list of staff managed by the nursery.
 * @param newStaff A pointer to the Staff object to be added.
 */
void Nursery::addStaff(Staff* newStaff) {
    if(newStaff)
        staff.push_back(newStaff);
}

/**
 * @brief Removes a garden from the nursery's list.
 * @param gardenToRemove A pointer to the Garden object to be removed.
 */
void Nursery::removeGarden(Garden* gardenToRemove) {
    for (size_t i = 0; i < gardens.size(); ++i) {
        if (gardens[i] == gardenToRemove) {
            gardens.erase(gardens.begin() + i);
            break; 
        }
    }
}

/**
 * @brief Removes a staff member from the nursery's list.
 * @param staffToRemove A pointer to the Staff object to be removed.
 */
void Nursery::removeStaff(Staff* staffToRemove) {
    for (size_t i = 0; i < staff.size(); ++i) {
        if (staff[i] == staffToRemove) {
            staff.erase(staff.begin() + i);
            break;  
        }
    }
}