#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H
#include "Customisation.h"

class Arrangement : public Customisation
{
private:
  bool addedArrangement;//to track if arrangement has been added
public:
  void setAddedArrangement(bool addedArrangement) { this->addedArrangement= addedArrangement; }//setter
  bool getAddedArrangement() const { return addedArrangement; }//getter
  void increasePrice();
  void addCust(Customer* customer);
};

#endif
