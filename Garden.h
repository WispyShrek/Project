#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "Staff.h"
#include <iostream>

class Garden : public Collection<Garden *> {
public:
  virtual ~Garden(){};
  Staff *staffList;
  void addItem(Garden *item);
  Iterator<Garden*> * CreateIterator();
  Garden *getCurrItem();
  bool isEmpty();
  void removeItem(Garden *item);
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

};

#endif
