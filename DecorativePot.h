#ifndef DECORATIVEPOT_H
#define DECORATIVEPOT_H
#include "Customisation.h"

class DecorativePot : public Customisation {

private:
  bool addedPot;//to track if decorative pot has been added
public:
  void setAddedPot(bool addedPot) { this->addedPot = addedPot; }//setter
  bool getAddedPot() const { return addedPot; }//getter
  void increasePrice();
  void addCust(Customer *customer);
  void print();
  std::string getName() override { return "DecorativePot"; }
  Plant* clone() override { return new DecorativePot(*this); }
};

#endif
