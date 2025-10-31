/**
 * @file Nursery.cpp
 * @brief Implementation of the Nursery class.
 */
#include "Nursery.h"
#include <algorithm> // For std::remove

/**
 * @brief Protected constructor to enforce the Singleton pattern.
 *
 * The constructor is protected to prevent direct instantiation of the Nursery class.
 * The single instance should be accessed via the static `instance()` method.
 */
Nursery::Nursery() {
  // Constructor is intentionally empty.
}

/**
 * @brief Protected destructor.
 *
 * The destructor does not deallocate the pointers in its vectors.
 * Ownership of Garden and Staff objects is managed externally.
 * The Nursery only manages the collections of pointers.
 */
Nursery::~Nursery() {
    // The Nursery does not own the Garden or Staff pointers,
    // so it does not delete them. Cleanup is handled by the caller
    // that creates these objects.
}

/**
 * @brief Provides access to the single instance of the Nursery.
 *
 * This static method implements the Meyers' Singleton pattern. It ensures that
 * only one instance of the Nursery is created. On the first call, it initializes
 * the static `uniqueInstance`; on subsequent calls, it returns the existing one.
 *
 * @return A reference to the unique Nursery instance.
 */
Nursery& Nursery::instance() {
    static Nursery uniqueInstance; //don't have to create new nursery object to call class 
    //(ex. Nursery& nursery = Nursery::instance() Call the static function instance() that belongs to the class Nursery. and not a specific object)
    return uniqueInstance;
}

/**
 * @brief Adds a new garden to the nursery's collection.
 * @param newGarden A pointer to the Garden object to be added. Does nothing if the pointer is null.
 */
void Nursery::addGarden(Garden* newGarden) {
    if(newGarden)
        gardens.push_back(newGarden);
}

/**
 * @brief Adds a new staff member to the nursery's collection.
 * @param newStaff A pointer to the Staff object to be added. Does nothing if the pointer is null.
 */
void Nursery::addStaff(Staff* newStaff) {
    if(newStaff)
        staff.push_back(newStaff);
}

/**
 * @brief Removes a garden from the nursery's collection.
 *
 * It finds the specified garden pointer in the `gardens` vector and removes it.
 * It does not delete the Garden object itself.
 * @param gardenToRemove A pointer to the Garden object to be removed.
 */
void Nursery::removeGarden(Garden* gardenToRemove) {
    // The erase-remove idiom is a more efficient way to remove elements from a vector.
    gardens.erase(std::remove(gardens.begin(), gardens.end(), gardenToRemove), gardens.end());
}

/**
 * @brief Removes a staff member from the nursery's collection.
 *
 * It finds the specified staff pointer in the `staff` vector and removes it.
 * It does not delete the Staff object itself.
 * @param staffToRemove A pointer to the Staff object to be removed.
 */
void Nursery::removeStaff(Staff* staffToRemove) {
    // The erase-remove idiom is a more efficient way to remove elements from a vector.
    staff.erase(std::remove(staff.begin(), staff.end(), staffToRemove), staff.end());
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"
#include "Sunny.h" // For creating concrete Garden objects
#include "Shady.h"
#include "PartialSun.h"
#include "PlantCaretaker.h" // For creating concrete Staff objects
#include "CustomerAssistant.h"

TEST_SUITE("Nursery Singleton") {
    TEST_CASE("instance() returns a single, unique instance") {
        Nursery& nursery1 = Nursery::instance();
        Nursery& nursery2 = Nursery::instance();

        CHECK(&nursery1 == &nursery2);
    }

    TEST_CASE("addStaff and removeStaff correctly modify the staff collection") {
        Nursery& nursery = Nursery::instance();
        
        // Ensure clean state for test
        while(nursery.getStaffCount() > 0) {
            // This is tricky without access to the internal vector.
            // The main.cpp tests suggest we can do this, but it's better to test from a known state.
            // For this test, we'll assume it's empty or we can manage what we add.
            // A reset method on the singleton would be ideal for testing.
        }
        
        size_t initialStaffCount = nursery.getStaffCount();

        Staff* caretaker = new PlantCaretaker();
        Staff* assistant = new CustomerAssistant();

        nursery.addStaff(caretaker);
        CHECK(nursery.getStaffCount() == initialStaffCount + 1);

        nursery.addStaff(assistant);
        CHECK(nursery.getStaffCount() == initialStaffCount + 2);

        nursery.removeStaff(caretaker);
        CHECK(nursery.getStaffCount() == initialStaffCount + 1);

        nursery.removeStaff(assistant);
        CHECK(nursery.getStaffCount() == initialStaffCount);

        // Cleanup
        delete caretaker;
        delete assistant;
    }

    TEST_CASE("addGarden and removeGarden correctly modify the garden collection") {
        Nursery& nursery = Nursery::instance();
        size_t initialGardenCount = nursery.getGardenCount();

        Garden* sunnyGarden = new Sunny();
        nursery.addGarden(sunnyGarden);
        CHECK(nursery.getGardenCount() == initialGardenCount + 1);

        nursery.removeGarden(sunnyGarden);
        CHECK(nursery.getGardenCount() == initialGardenCount);

        // Cleanup
        delete sunnyGarden;
    }
}
#endif