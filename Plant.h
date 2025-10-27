#ifndef PLANT_H
#define PLANT_H
#include "CareStrategy.h"
#include "Garden.h"
#include "PlantMemento.h"
#include "PlantState.h"
#include <string>

class Plant : public Garden {

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
  void nextState();
  void prevState();
  void applyCare();
  void Print();
  void addCust();
  PlantMemento *createPlantMemento();
  void setPlantMemento(PlantMemento *memento);
  virtual Plant *clone() = 0;

protected:
  Plant(Plant &toCopy);
};

#endif
