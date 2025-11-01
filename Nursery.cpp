#include "Nursery.h"

Nursery::Nursery()
{
    // TODO - implement Nursery::Nursery
    // initialize noting in constructor as to not be able to create a new instance of the nursery pointer
}

Nursery::~Nursery()
{
    // assuming that at some point nursery gets deleted the gardens and staff in it gets deleted as well
    //  for (Garden* g : gardens) {
    //    delete g;
    //  }
    //  gardens.clear();

    // for (Staff* s : staff) {
    //     delete s;
    // }
    // staff.clear();
}

Nursery &Nursery::instance()
{
    static Nursery uniqueInstance; // don't have to create new nursery object to call class
    //(ex. Nursery& nursery = Nursery::instance() Call the static function instance() that belongs to the class Nursery. and not a specific object)
    return uniqueInstance;
}

// uniqueInstance is a local sstatic variable inside the function, first time instance futnion called, compiler intializes uniqueInstance.
// On future calls it just returns the already-created object.

// Nursery::Nursery(Nursery &in) {
//   // TODO - implement Nursery::Nursery
// }

// add garden to list/*state*
void Nursery::addGarden(Garden *newGarden)
{
    if (newGarden)
        gardens.push_back(newGarden);
}

// add staff to list/*state*
void Nursery::addStaff(Staff *newStaff)
{
    if (newStaff)
        staff.push_back(newStaff);
}

// remove garden from *state*
void Nursery::removeGarden(Garden *gardenToRemove)
{
    for (size_t i = 0; i < gardens.size(); ++i)
    {
        if (gardens[i] == gardenToRemove)
        {
            gardens.erase(gardens.begin() + i);
            break;
        }
    }
}

// remove staff from *state*
void Nursery::removeStaff(Staff *staffToRemove)
{
    for (size_t i = 0; i < staff.size(); ++i)
    {
        if (staff[i] == staffToRemove)
        {
            staff.erase(staff.begin() + i);
            break;
        }
    }
}
// spawns customers randomly at random intervals
void Nursery::customerSpawner()
{
    using namespace std::chrono_literals;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> stratDist(0, 2);      // 0=EFT, 1=Card, 2=Cash
    std::uniform_int_distribution<int> custDist(0, 1);       // 0=Fussy, 1=Easy
    std::uniform_int_distribution<int> delayDist(500, 1500); // delay in ms

    bool running = true; // optional: could be controlled externally

    while (running)
    {
        // Sleep for a random interval
        std::this_thread::sleep_for(std::chrono::milliseconds(delayDist(gen)));

        // Choose a payment strategy
        PaymentStrategy *strategy = nullptr;
        switch (stratDist(gen))
        {
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

        // Generate preferred plants (example placeholder)
        std::vector<Plant *> preferredPlants;
        // TODO: populate preferredPlants here

        // Create a random customer
        Customer *newCustomer = nullptr;
        customers.push_back(newCustomer);
        if (custDist(gen) == 0)
        {
            newCustomer = new FussyCust("Fussy Customer", salesFloor, strategy, preferredPlants);
            cout << "Fussy Customer created" << endl;
        }
        else
        {
            newCustomer = new EasyCust("Easy Customer", salesFloor, strategy, preferredPlants);
            cout << "Easy Customer created" << endl;
            
        }
        running=false;
    }
    for(int i =0;i<int(customers.size());i++){
        delete customers[i];
        customers[i]=NULL;
    }
}