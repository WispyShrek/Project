#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "Customer.h"
#include "SalesFloor.h"

/**
 * @class Staff
 * @brief An abstract base class representing staff members in the nursery.
 *
 * The Staff class defines common behaviors for all staff types,
 * including care services and notification handling. It inherits from SalesFloor.
 */
class Staff : public SalesFloor
{
public:
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
};

#endif