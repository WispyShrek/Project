/**
 * @file Nursery.cpp
 * @brief Implementation of the Nursery class.
 */
#include "Nursery.h"
#include <algorithm> // For std::remove

/**
 * @brief Protected constructor to enforce the Singleton pattern.
 *
 * The constructor is protected to prevent direct instantiation of the Nursery
 * class. The single instance should be accessed via the static `instance()`
 * method.
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
 * only one instance of the Nursery is created. On the first call, it
 * initializes the static `uniqueInstance`; on subsequent calls, it returns the
 * existing one.
 *
 * @return A reference to the unique Nursery instance.
 */
Nursery &Nursery::instance() {
  static Nursery
      uniqueInstance; // don't have to create new nursery object to call class
  //(ex. Nursery& nursery = Nursery::instance() Call the static function
  // instance() that belongs to the class Nursery. and not a specific object)
  return uniqueInstance;
}

// uniqueInstance is a local sstatic variable inside the function, first time
// instance futnion called, compiler intializes uniqueInstance. On future calls
// it just returns the already-created object.

// Nursery::Nursery(Nursery &in) {
//   // TODO - implement Nursery::Nursery
// }

const vector<Staff *> &Nursery::getStaff() { return this->staff; }

void Nursery::addToBalance(double toAdd) { this->balance += toAdd; }
bool Nursery::removeFromBalance(double toRemove) {
  if (balance >= toRemove) {
    balance -= toRemove;
    return true;
  }
  return false;
}
double Nursery::getBalance() { return this->balance; }

const vector<Garden *> &Nursery::getGardens() { return this->gardens; };

// add garden to list/*state*
void Nursery::addGarden(Garden *newGarden) {
  if (newGarden)
    gardens.push_back(newGarden);
}

// add staff to list/*state*
void Nursery::addStaff(Staff *newStaff) {
  if (newStaff)
    staff.push_back(newStaff);
}

// remove garden from *state*
void Nursery::removeGarden(Garden *gardenToRemove) {
  for (size_t i = 0; i < gardens.size(); ++i) {
    if (gardens[i] == gardenToRemove) {
      gardens.erase(gardens.begin() + i);
      break;
    }
  }
}
void Nursery::addToPlantInventory(Plant *inventory) {
  if (inventory == nullptr) {
    return;
  }
  if (inventory->getState() == "Mature") {
    salesFloor->addToPlantInventory(inventory);
  } else {
    plantInventory.push_back(inventory);
  }
}

Plant *Nursery::removeFromPlantInventory() {
  if (plantInventory.size() > 0) {
    Plant *returned = plantInventory.back();
    plantInventory.pop_back();
    return returned;
  }
  return nullptr;
}

// remove staff from *state*

void Nursery::removeStaff(Staff *staffToRemove) {
  for (size_t i = 0; i < staff.size(); ++i) {
    if (staff[i] == staffToRemove) {
      staff.erase(staff.begin() + i);
      break;
    }
  }
}
// spawns customers randomly at random intervals

/**
 * @brief Spawns a customer with randomized preferences and payment strategy.
 *
 * This method simulates customer creation at random intervals. It randomly
 * selects a payment strategy, plant preferences, and customer type (Easy or
 * Fussy). The created customer is added to the nursery's internal list and
 * deleted after use.
 */
void Nursery::customerSpawner() {
  using namespace std::chrono_literals;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> stratDist(0, 2); // 0=EFT, 1=Card, 2=Cash
  std::uniform_int_distribution<int> custDist(0, 1);  // 0=Fussy, 1=Easy
  std::uniform_int_distribution<int> delayDist(500, 1500); // delay in ms

  bool running = true; // optional: could be controlled externally

  while (running) {
    // Sleep for a random interval
    std::this_thread::sleep_for(std::chrono::milliseconds(delayDist(gen)));

    // Choose a payment strategy
    PaymentStrategy *strategy = nullptr;
    switch (stratDist(gen)) {
    case 0:
      strategy = new EFT();
      break;
    case 1:
      strategy = new Card();
      break;
    case 2:
      strategy = new Cash();
      break;
    }

    std::vector<Plant *> preferredPlants;
    int listSize = rand() % 10 + 1;
    int decorationSize = rand() % 3;

    for (int i = 0; i < listSize; i++) {
      std::cout << "Generating preferred plant " << i + 1 << std::endl;
      // Create a random plant and add it to the preferredPlants vector
      Plant *newPlant = nullptr;
      int plantType = rand() % 4;
      switch (plantType) {
      case 0:
        newPlant = new Lily();
        break;
      case 1:
        newPlant = new Tulip();
        break;
      case 2:
        newPlant = new Lavender();
        break;
      case 3:
        newPlant = new Rose();

      default:
        newPlant = new Lily(); // Fallback
        break;
      }
      int decorationType = rand() % 3;
      for (int j = 0; j < decorationSize; j++) {
        switch (decorationType) {
        case 0:
          newPlant = new Arrangement(); // wrap with Arrangement
          break;
        case 1:
          newPlant = new Giftwrapping(); // wrap with Giftwrapping
          break;
        case 2:
          newPlant = new DecorativePot(); // wrap with DecorativePot
          break;
        default:
          break;
        }
      }
      preferredPlants.push_back(newPlant);
    }
    double time = static_cast<double>(
        rand() % 11 + 5); // time available between 5 and 15 minutes
    // Create a random customer
    Customer *newCustomer = nullptr;
    customers.push_back(newCustomer);
    if (custDist(gen) == 0) {
      newCustomer = new FussyCust("Fussy Customer", salesFloor, time, strategy,
                                  preferredPlants);
    } else {
      newCustomer = new EasyCust("Easy Customer", salesFloor, time, strategy,
                                 preferredPlants);
    }
    running = false;
  }
  for (int i = 0; i < int(customers.size()); i++) {
    delete customers[i];
    customers[i] = NULL;
  }
}
/**
 * @brief Adds a new garden to the nursery's collection.
 * @param newGarden A pointer to the Garden object to be added. Does nothing if
 * the pointer is null.
 */

#ifdef ENABLE_DOCTESTS
#include "CustomerAssistant.h"
#include "PartialSun.h"
#include "PlantCaretaker.h" // For creating concrete Staff objects
#include "Shady.h"
#include "Sunny.h" // For creating concrete Garden objects
#include "doctest.h"

TEST_SUITE("Nursery Singleton") {
  TEST_CASE("instance() returns a single, unique instance") {
    Nursery &nursery1 = Nursery::instance();
    Nursery &nursery2 = Nursery::instance();

    CHECK(&nursery1 == &nursery2);
  }

  TEST_CASE("addStaff and removeStaff correctly modify the staff collection") {
    Nursery &nursery = Nursery::instance();

    // Ensure clean state for test
    while (nursery.getStaffCount() > 0) {
      // This is tricky without access to the internal vector.
      // The main.cpp tests suggest we can do this, but it's better to test from
      // a known state. For this test, we'll assume it's empty or we can manage
      // what we add. A reset method on the singleton would be ideal for
      // testing.
    }

    size_t initialStaffCount = nursery.getStaffCount();

    Staff *caretaker = new PlantCaretaker();
    Staff *assistant = new CustomerAssistant();

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

  TEST_CASE(
      "addGarden and removeGarden correctly modify the garden collection") {
    Nursery &nursery = Nursery::instance();
    size_t initialGardenCount = nursery.getGardenCount();

    Garden *sunnyGarden = new Sunny();
    nursery.addGarden(sunnyGarden);
    CHECK(nursery.getGardenCount() == initialGardenCount + 1);

    nursery.removeGarden(sunnyGarden);
    CHECK(nursery.getGardenCount() == initialGardenCount);

    Garden *sunnyGarden = new Sunny();
    nursery.addGarden(sunnyGarden);
    CHECK(nursery.getGardenCount() == initialGardenCount + 1);

    nursery.removeGarden(sunnyGarden);
    CHECK(nursery.getGardenCount() == initialGardenCount);

    // Cleanup
    delete sunnyGarden;
  }
  TEST_CASE("customerSpawner creates customers without crashing") {
    Nursery &nursery = Nursery::instance();

    // This test just ensures that the method runs without exceptions.
    // In a real test, we would want to mock dependencies and verify behavior.
    CHECK_NOTHROW(nursery.customerSpawner());
  }
}
#endif
