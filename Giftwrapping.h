#ifndef GIFTWRAPPING_H
#define GIFTWRAPPING_H
#include "Customisation.h"

class Giftwrapping : public Customisation {
private:
  bool addedWrapping; // to track if giftwrapping has been added
public:
  void setAddedWrapping(bool addedWrapping) {
    this->addedWrapping = addedWrapping;
  } // setter
  bool getAddedWrapping() const { return addedWrapping; } // getter
  void increasePrice() override;
  void addCust(Customer *customer) override;
  std::string print() override;
  std::string getName() override { return "Giftwrapping"; }
  Plant *clone() override { return new Giftwrapping(*this); }
};

#endif
