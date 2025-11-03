#ifndef GIFTWRAPPING_H
#define GIFTWRAPPING_H
#include "Customisation.h"

class Giftwrapping : public Customisation
{
private:
  bool addedWrapping;
public:
  void setAddedWrapping(bool addedWrapping) { this->addedWrapping= addedWrapping; }
  bool getAddedWrapping() const { return addedWrapping; }
  void increasePrice();
  void addCust(Customer *customer);
};

#endif
