#ifndef STAFF_H
#define STAFF_H
#include <vector>
#include "Customer.h"
#include "SalesFloor.h"

/** @class Staff
 * @brief An abstract base class representing staff members in the nursery.
 * 
 * The Staff class defines common behaviors for all staff types,
 * including care services and notification handling.
 */

class Staff : public SalesFloor
{

public:
  /** @fn Staff::~Staff()
   * @brief Virtual destructor for the Staff class.
   */
  virtual ~Staff(){};
  virtual void care() = 0;
  virtual bool notify(Customer *customer, Plant* plant) =0;
  virtual void update() {};
};

#endif
