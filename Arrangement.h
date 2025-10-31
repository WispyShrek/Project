#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H
#include "Customisation.h"

class Arrangement : public Customisation
{
private:
  bool addedArrangement;
public:
  void setAddedArrangement(bool addedArrangement) { this->addedArrangement= addedArrangement; }
  bool getAddedArrangement() const { return addedArrangement; }
  void increasePrice();
  void addCust(Customer* customer);
};

#endif
