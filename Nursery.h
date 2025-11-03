#ifndef NURSERY_H
#define NURSERY_H
#include "Arrangement.h"
#include "Card.h"
#include "Cash.h"
#include "Customer.h"
#include "DecorativePot.h"
#include "EFT.h"
#include "EasyCust.h"
#include "FussyCust.h"
#include "Garden.h"
#include "Giftwrapping.h"
#include "Lavender.h"
#include "Lily.h"
#include "Rose.h"
#include "SalesFloor.h"
#include "Staff.h"
#include "Tulip.h"
#include "greenHouse.h"

#include <chrono>
#include <random>
#include <thread>
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
  SalesFloor *salesFloor;
  static Nursery *uniqueInstance;
  vector<Garden *> gardens;
  vector<Plant *> plantInventory;
  double balance = 0;
  /**
   * @var vector<greenHouse*> greenHouses
   * @brief A collection of all greenhouses in the nursery.
   */
  vector<greenHouse *> greenHouses;
  /**
   * @var vector<Staff*> staff
   * @brief A collection of all staff members in the nursery.
   */
  vector<Staff *> staff;
  vector<Customer *> customers;

public:
  /**
   * @fn static Nursery& Nursery::instance()
   * @brief Provides access to the single instance of the Nursery.
   *
   * This static method ensures that only one instance of the Nursery is
   * created. On the first call, it creates the instance; on subsequent calls,
   * it returns the existing instance.
   * @return A reference to the unique Nursery instance.
   */
  static Nursery &instance();
  /* @brief Returns a reference to the nursery's stafflist
   * @return A reference to a vector of staff pointers
   */
  const std::vector<Staff *> &getStaff();
  /* @brief Returns a reference to the nursery's garden list
   * @return A reference to a vector of garden pointers
   */
  const std::vector<Garden *> &getGardens();

  /** @fn void Nursery::addGarden(Garden* newgarden)
   * @brief Adds a new garden to the nursery.
   * @param newgarden A pointer to the Garden object to be added.
   */

  void addGarden(Garden *newgarden);
  /* @brief adds an amount from the nursery's balance
   * @param (double) amount to add
   */
  void addToBalance(double toAdd);
  /* @brief removes an amount from the nursery's balance
   * If the amount exceeds the balance nothing happens
   * @param (double) amount to remove
   * @return boolean representing that the value could be removed;
   */
  bool removeFromBalance(double toRemove);
  /* @brief returns the balance of the nursery
   * @return A double representing the balance of the nursery
   */
  double getBalance();
  /**
   * @fn void Nursery::addStaff(Staff* newStaff)
   * @brief Adds a new staff member to the nursery.
   * @param newStaff A pointer to the Staff object to be added.
   */
  void addStaff(Staff *newStaff);
  /**
   * @fn void Nursery::removeStaff(Staff* staffToRemove)
   * @brief Removes a staff member from the nursery.
   * @param staffToRemove A pointer to the Staff object to be removed.
   */
  void removeStaff(Staff *staffToRemove);
  /**@fn void addToPlantInventory(Plant *);
   *@brief Adds a plant to the nursery inventory
   *If the plant is mature, automatically transfers the item to the salesfloor
   * to be sold
   *@param Plant pointer to be added to plantInventory
   */
  void addToPlantInventory(Plant *inventory);
  /**@fn void addToPlantInventory(Plant *);
   *@brief Removes a plant to the nursery inventory
   *@return Plant pointer to the removed plant
   */
  Plant *removeFromPlantInventory();

  /**
   * @fn void Nursery::removeGarden(Garden* gardenToRemove)
   * @brief Removes a garden from the nursery.
   * @param gardenToRemove A pointer to the Garden object to be removed.
   */
  void removeGarden(Garden *gardenToRemove);
  /**
   * @brief Spawns a customer with randomized preferences and payment strategy.
   *
   * This function simulates customer creation at random intervals. It randomly
   * selects a payment strategy (EFT, Card, or Cash), plant preferences
   * (including optional decorations), and customer type (Easy or Fussy). The
   * created customer is added to the nursery's internal list and deleted after
   * use. Intended for dynamic simulation of customer behavior.
   */

  void customerSpawner();

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
