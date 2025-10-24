#ifndef PLANT_H
#define PLANT_H
#include "CareStrategy.h"
#include "Garden.h"
#include "PlantMemento.h"
#include "PlantState.h"
#include <string>
#include <iostream>

class Plant{

private:
  PlantState *currState;
  CareStrategy *strategy;
  std::string colour;
  std::string scent;
  int length;

public:
  Plant();
  virtual ~Plant();
  std::string getState();
  void setState(PlantState *state);
  void nextState();
  void prevState();
  void applyCare();
  virtual void print();
  void addCust();
  PlantMemento *createPlantMemento();
  void setPlantMemento(PlantMemento *memento);
  virtual Plant *clone() = 0;

protected:
  Plant(Plant &toCopy);
};

#endif
