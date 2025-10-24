#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "Staff.h"
#include <iostream>
#include <vector>
#include "GardenIterator.h"
#include "Plant.h"

class Garden : public Collection<Plant *> {
public:
  virtual ~Garden();
  Staff *staffList;

  //the methods used for the iterator DP, the concrete methods.
  void addItem(Plant* item) override;
  Iterator<Plant*> * CreateIterator() override;
  void removeItem(Plant* item) override;

  void TemplateMethod();
  //virtual void applyRays() = 0;
  void attach(Staff *staff);
  void detach(Staff *staff);
  void notify();
private:
  std::vector<Plant*> plants;

};

#endif
