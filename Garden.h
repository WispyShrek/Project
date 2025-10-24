#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "Staff.h"
#include <iostream>
#include "GardenIterator.h"

class Garden : public Collection<Garden *> {
public:
  virtual ~Garden(){};
  Staff *staffList;

  //the methods used for the iterator DP, the concrete methods.
  void addItem(Garden *item) override;
  Iterator<Garden*> * CreateIterator() override;
  void removeItem(Garden *item) override;

  void TemplateMethod();
  //virtual void applyRays() = 0;
  void attach(Staff *staff);
  void detach(Staff *staff);
  void notify();

  //abstract methods for composite pattern ( not included previously, to add to class diagram)
  virtual void addGarden(Garden *g){(void)g;}
  virtual void removeGarden(Garden *g){(void)g;}
  virtual void print(){}
  virtual void printChild(int param){}
private:
  std::vector<Garden*> children;

};

#endif
