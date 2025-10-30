#ifndef NURSERY_H
#define NURSERY_H
#include "Garden.h"
#include "Staff.h"
#include "greenHouse.h"
#include <vector>
using namespace std;

class Nursery {

private:
  static Nursery *uniqueInstance;
  vector<Garden*> gardens;
  vector<greenHouse*> greenHouses;
  vector<Staff*> staff;
  

public:
  static Nursery& instance();
  void addGarden(Garden* newgarden); 
  void addStaff(Staff* newStaff);
  void removeStaff(Staff* staffToRemove);
  void removeGarden(Garden* gardenToRemove); 

  //helps for debugging
  size_t getGardenCount() const { return gardens.size(); } 
  size_t getStaffCount() const { return staff.size(); }

protected:
  Nursery();
  ~Nursery();
  // Nursery(Nursery &in);
};

#endif
