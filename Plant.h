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

class Plant {

private:
  PlantState *currState;
  CareStrategy *strategy;
  std::string colour;
  std::string scent;
  int length;
  double price;
public:
  Plant();
<<<<<<< HEAD
  ~Plant();
  void increasePrice(double amount);
=======
  virtual ~Plant();
>>>>>>> origin/Marco
  std::string getState();
  void setState(PlantState *state);
  std::string getStrategy();
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
