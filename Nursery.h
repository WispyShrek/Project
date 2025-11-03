#ifndef NURSERY_H
#define NURSERY_H
#include "Garden.h"
#include "Staff.h"
#include "greenHouse.h"
#include <vector>
using namespace std;

/**
 * @class Nursery
 * @brief Manages the entire nursery, including gardens, greenhouses, and staff.
 *
 * This class is implemented as a Singleton, ensuring that only one instance
 * of the nursery exists throughout the application. It provides a central
 * point of access for managing all major components of the nursery.
 */
class Nursery {

private:
  /**
   * @var vector<Garden*> gardens
   * @brief A collection of all gardens in the nursery.
   */
  vector<Garden*> gardens;
  /**
   * @var vector<greenHouse*> greenHouses
   * @brief A collection of all greenhouses in the nursery.
   */
  vector<greenHouse*> greenHouses;
  /**
   * @var vector<Staff*> staff
   * @brief A collection of all staff members in the nursery.
   */
  vector<Staff*> staff;
  

public:
  /**
   * @fn static Nursery& Nursery::instance()
   * @brief Provides access to the single instance of the Nursery.
   *
   * This static method ensures that only one instance of the Nursery is created.
   * On the first call, it creates the instance; on subsequent calls, it returns
   * the existing instance.
   * @return A reference to the unique Nursery instance.
   */
  static Nursery& instance();
  /**
   * @fn void Nursery::addGarden(Garden* newgarden)
   * @brief Adds a new garden to the nursery.
   * @param newgarden A pointer to the Garden object to be added.
   */
  void addGarden(Garden* newgarden); 
  /**
   * @fn void Nursery::addStaff(Staff* newStaff)
   * @brief Adds a new staff member to the nursery.
   * @param newStaff A pointer to the Staff object to be added.
   */
  void addStaff(Staff* newStaff);
  /**
   * @fn void Nursery::removeStaff(Staff* staffToRemove)
   * @brief Removes a staff member from the nursery.
   * @param staffToRemove A pointer to the Staff object to be removed.
   */
  void removeStaff(Staff* staffToRemove);
  /**
   * @fn void Nursery::removeGarden(Garden* gardenToRemove)
   * @brief Removes a garden from the nursery.
   * @param gardenToRemove A pointer to the Garden object to be removed.
   */
  void removeGarden(Garden* gardenToRemove); 

  /**
   * @fn size_t Nursery::getGardenCount() const
   * @brief Gets the current number of gardens in the nursery.
   * This function is primarily for debugging purposes.
   * @return The number of gardens.
   */
  size_t getGardenCount() const { return gardens.size(); } 
  /**
   * @fn size_t Nursery::getStaffCount() const
   * @brief Gets the current number of staff members in the nursery.
   * This function is primarily for debugging purposes.
   * @return The number of staff members.
   */
  size_t getStaffCount() const { return staff.size(); }

protected:
  /**
   * @brief Protected constructor to enforce the Singleton pattern.
   */
  Nursery();
  /**
   * @brief Protected destructor.
   */
  ~Nursery();
  // Nursery(Nursery &in);
};

#endif 
