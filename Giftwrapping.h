#ifndef GIFTWRAPPING_H
#define GIFTWRAPPING_H
#include "Customisation.h"

class Giftwrapping : public Customisation
{
private:
  bool addedWrapping;//to track if giftwrapping has been added
public:
  void setAddedWrapping(bool addedWrapping) { this->addedWrapping= addedWrapping; }//setter
  bool getAddedWrapping() const { return addedWrapping; }//getter
  void increasePrice();
  void addCust(Customer *customer);
};

#endif
