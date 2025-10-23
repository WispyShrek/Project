#ifndef GARDEN_H
#define GARDEN_H
#include "Collection.h"
#include "Staff.h"

class Garden : public Collection<Garden *> {
public:
  Staff *staffList;
  virtual void Print() = 0;
  void addItem(Garden *item);
  Iterator<Garden *> *CreateIterator();
  Garden *getCurrItem();
  bool isEmpty();
  void removeItem(Garden *item);
  void TemplateMethod();
  virtual void applyRays() = 0;
  void attach(Staff *staff);
  void detach(Staff *staff);
  void notify();
};

#endif
