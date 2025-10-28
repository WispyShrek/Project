#ifndef DECORATIVEPOT_H
#define DECORATIVEPOT_H
#include "Customisation.h"

class DecorativePot : public Customisation {

private:
  bool addedPot;
public:
  void setAddedPot(bool addedPot) { this->addedPot = addedPot; }
  bool getAddedPot() const { return addedPot; }
  void increasePrice();
  void addCust(Customer *customer);
};

#endif
