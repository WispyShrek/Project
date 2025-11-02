#ifndef STAFF_H
#define STAFF_H
#include "Customer.h"
#include "SalesFloor.h"
#include <vector>

/** @class Staff
 * @brief An abstract base class representing staff members in the nursery.
 *
 * The Staff class defines common behaviors for all staff types,
 * including care services and notification handling.
 */

class Staff : public SalesFloor {
  std::string name;
  std::string description;
  int cost = 200;

public:
  /** @fn Staff::~Staff()
   * @brief Virtual destructor for the Staff class.
   */
  virtual ~Staff() {};
  virtual void care() = 0;
  virtual bool notify(Customer *customer, Plant* plant) =0;
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
