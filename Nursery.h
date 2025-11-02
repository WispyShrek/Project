#ifndef NURSERY_H
#define NURSERY_H
#include "Garden.h"
#include "Staff.h"
#include "greenHouse.h"
#include "Customer.h"
#include "EasyCust.h"
#include "FussyCust.h"
#include "EFT.h"
#include "Card.h"
#include "Cash.h"
#include "SalesFloor.h"
#include "Lily.h"
#include "Tulip.h"
#include "Lavender.h"
#include "Rose.h"
#include "DecorativePot.h"
#include "Giftwrapping.h"
#include "Arrangement.h"

#include <vector>
#include <chrono>
#include <thread>
#include <random>
using namespace std;

class Nursery {

private:
  SalesFloor* salesFloor;
  static Nursery *uniqueInstance;
  vector<Garden*> gardens;
  vector<greenHouse*> greenHouses;
  vector<Staff*> staff;
  vector<Customer*> customers;

public:
  static Nursery& instance();
  void addGarden(Garden* newgarden); 
  void addStaff(Staff* newStaff);
  void removeStaff(Staff* staffToRemove);
  void removeGarden(Garden* gardenToRemove); 
  void customerSpawner();

  //helps for debugging
  size_t getGardenCount() const { return gardens.size(); } 
  size_t getStaffCount() const { return staff.size(); }

protected:
  Nursery();
  ~Nursery();
  // Nursery(Nursery &in);
};

#endif
