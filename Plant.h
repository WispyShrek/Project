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
class Customer;
class Plant
{

protected:
  Customer *customer;
  PlantState *currState;
  CareStrategy *strategy;
  std::string colour;
  std::string scent;
  int length;
  double price;

public:
  Plant();
  virtual ~Plant();
  const bool& operator==(const Plant& other);
  void increasePrice(double amount);
  std::string getState();
  void setState(PlantState *state);
  std::string getStrategy();
  virtual std::string getName() = 0;
  void setStrategy(CareStrategy *strategy);
  std::string getColour();
  std::string getScent();
  std::string getPrice();
  void nextState();
  void prevState();
  void setCareStrategy(CareStrategy* s);//added this for the Strategy design pattern
  void applyCare();
  virtual void print();
  void addCust(Customer *customer);
  PlantMemento *createPlantMemento();
  void setPlantMemento(PlantMemento *memento);
  virtual Plant *clone() = 0;

protected:
  Plant(Plant &toCopy);
};

#endif
