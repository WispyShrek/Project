#include "Nursery.h"

Nursery::Nursery() {
  // TODO - implement Nursery::Nursery
  //initialize noting in constructor as to not be able to create a new instance of the nursery pointer
}

Nursery::~Nursery() {
  //assuming that at some point nursery gets deleted the gardens and staff in it gets deleted as well
    // for (Garden* g : gardens) {
    //   delete g;
    // }
    // gardens.clear();

    // for (Staff* s : staff) {
    //     delete s;
    // }
    // staff.clear();

}

Nursery& Nursery::instance() {
    static Nursery uniqueInstance; //don't have to create new nursery object to call class 
    //(ex. Nursery& nursery = Nursery::instance() Call the static function instance() that belongs to the class Nursery. and not a specific object)
    return uniqueInstance;
}

//uniqueInstance is a local sstatic variable inside the function, first time instance futnion called, compiler intializes uniqueInstance. 
//On future calls it just returns the already-created object.

// Nursery::Nursery(Nursery &in) {
//   // TODO - implement Nursery::Nursery
// }

//add garden to list/*state*
void Nursery::addGarden(Garden* newGarden) {
    if(newGarden)
        gardens.push_back(newGarden);
}

//add staff to list/*state*
void Nursery::addStaff(Staff* newStaff) {
    if(newStaff)
        staff.push_back(newStaff);
}

//remove garden from *state*
void Nursery::removeGarden(Garden* gardenToRemove) {
    for (size_t i = 0; i < gardens.size(); ++i) {
        if (gardens[i] == gardenToRemove) {
            gardens.erase(gardens.begin() + i);
            break; 
        }
    }
}

//remove staff from *state*
void Nursery::removeStaff(Staff* staffToRemove) {
    for (size_t i = 0; i < staff.size(); ++i) {
        if (staff[i] == staffToRemove) {
            staff.erase(staff.begin() + i);
            break;  
        }
    }
}