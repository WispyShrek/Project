#ifndef PLANT_H
#define PLANT_H
#include "CareStrategy.h"
#include "Dying.h"
#include "Flowering.h"
#include "Garden.h"
#include "Mature.h"
#include "PlantMemento.h"
#include "PlantState.h"
#include "Sprout.h"
#include <iostream>
#include <string>
using namespace std;
class Plant
{

private:
  PlantState *currState;
  CareStrategy *strategy;
  std::string colour;
  std::string scent;
  int length;
  double price;

public:
  Plant();
  ~Plant();
  void increasePrice(double amount);
  std::string getState();
  void setState(PlantState *state);
  string getStrategy();
  virtual string getName() = 0;
  void setStrategy(CareStrategy *strategy);
  string getColour();
  string getScent();
  string getPrice();
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
