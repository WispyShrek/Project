#ifndef NURSERY_H
#define NURSERY_H
#include "Garden.h"
#include "Staff.h"
#include <vector>
using namespace std;

/**
 * @class Nursery
 * @brief Manages all gardens and staff members using the Singleton design pattern.
 *
 * The Nursery class ensures that only one instance of itself exists throughout the
 * application. It provides a global point of access to this instance. It is responsible
 * for holding collections of gardens and staff members. Note that the Nursery does not
 * take ownership of the pointers it stores; memory management of gardens and staff
 * must be handled externally.
 */
class Nursery {

private:
  vector<Garden*> gardens;
  vector<Staff*> staff;
  

public:
  /**
   * @brief Provides access to the single instance of the Nursery.
   * @return A reference to the unique Nursery object.
   */
  static Nursery& instance();

  /**
   * @brief Adds a garden to the nursery's collection.
   * @param newgarden A pointer to the Garden to add.
   */
  void addGarden(Garden* newgarden); 

  /**
   * @brief Adds a staff member to the nursery's collection.
   * @param newStaff A pointer to the Staff member to add.
   */
  void addStaff(Staff* newStaff);

  /**
   * @brief Removes a staff member from the nursery's collection.
   * @param staffToRemove A pointer to the Staff member to remove.
   */
  void removeStaff(Staff* staffToRemove);

  /**
   * @brief Removes a garden from the nursery's collection.
   * @param gardenToRemove A pointer to the Garden to remove.
   */
  void removeGarden(Garden* gardenToRemove); 

  /** @brief Gets the current number of gardens. @return The count of gardens. */
  size_t getGardenCount() const { return gardens.size(); } 
  /** @brief Gets the current number of staff members. @return The count of staff members. */
  size_t getStaffCount() const { return staff.size(); }

protected:
  Nursery();
  ~Nursery();
};

#endif
