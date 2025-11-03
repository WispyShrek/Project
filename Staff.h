#ifndef STAFF_H
#define STAFF_H

#include "Customer.h"
#include "SalesFloor.h"
#include <vector>

/**
 * @class Staff
 * @brief An abstract base class representing staff members in the nursery.
 *
 * The Staff class defines common behaviors for all staff types,
 * including care services and notification handling. It inherits from
 * SalesFloor.
 */

class Staff : public SalesFloor {
private:
  std::string name;
  std::string description;
  int cost = 200;

public:
  Staff() {
    this->name = "TestStaff";
    this->description = "No description available";
  }

  /**
   * @brief Virtual destructor for the Staff class.
   */
  virtual ~Staff() {};

  /**
   * @brief Pure virtual method to perform care-related tasks.
   *
   * Implemented by derived classes to define specific care behavior.
   */
  virtual void care() = 0;

  /**
   * @brief Pure virtual method to handle customer notifications.
   *
   * @param customer Pointer to the Customer object.
   * @param plant Pointer to the Plant object.
   * @return True if the notification was successfully handled.
   */
  virtual bool notify(Customer *customer, Plant *plant) = 0;

  /**
   * @brief Optional method to receive updates from observable subjects.
   *
   * Can be overridden by derived classes to respond to changes in state.
   */
  virtual void update() {};
  void setName(std::string name) { this->name = name; };
  void setDescription(std::string description) {
    this->description = description;
  };
  std::string getName() { return this->name; };
  int getCost() { return this->cost; };
  std::string getDescription() {
    return this->description + "\nCost to hire: R" + std::to_string(cost);
  };
};

#endif
