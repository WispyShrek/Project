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

/** @class Plant
 * @brief An abstract base class representing a plant in the nursery.
 * 
 * The Plant class defines common attributes and behaviors for all plant types,
 * including state management, care strategies, and cloning functionality.
 */

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
  /** @fn Plant::Plant()
   * @brief Constructor for the Plant class.
   */
  Plant();
  /** @fn Plant::~Plant()
   * @brief Destructor for the Plant class.
   */
  virtual ~Plant();
  /** @fn const bool& Plant::operator==(const Plant& other)
   * @brief Equality operator to compare two Plant objects.
   * @param other A reference to the other Plant object to compare with.
   * @return A boolean indicating whether the two Plant objects are equal.
   */
  const bool& operator==(const Plant& other);
  /** @fn  void Plant::increasePrice(double amount)
   * @brief Increases the price of the plant by a specified amount.
   * @param amount The amount to increase the price by.
  */
  void increasePrice(double amount);
  /** @fn std::string Plant::getState()
   * @brief Retrieves the current state of the plant as a string.
   * @return A string representing the current state of the plant.
   */
  std::string getState();
  /** @fn void Plant::setState(PlantState *state)
   * @brief Sets the current state of the plant.
   * @param state A pointer to the new PlantState to set.
   */
  void setState(PlantState *state);
  /** @fn std::string Plant::getStratergy()
   * @brief Retrieves the name of the current care strategy.
   * @return A string representing the name of the care strategy.
   */
  std::string getStrategy();

  virtual std::string getName() = 0;
  /** @fn void Plant::setStrategy(CareStrategy *strategy)
   * @brief Sets the care strategy for the plant.
   * @param strategy A pointer to the CareStrategy to set.
   */
  void setStrategy(CareStrategy *strategy);
  /** @fn setd::string Plant::getColour()
   * @brief Retrieves the colour of the plant.
   * @return A string representing the colour of the plant.
   */
  std::string getColour();
  /** @fn std::string Plant::getScent()
   * @brief Retrieves the scent of the plant.
   * @return A string representing the scent of the plant.
   */
  std::string getScent();
  /** @fn std::string Plant::getPrice()
   * @brief Retrieves the price of the plant.
   * @return A string representing the price of the plant.
   */
  std::string getPrice();
  /** @fn void Plant::nextState()
   * @brief Transitions the plant to the next state.
   */
  void nextState();
  /** @fn void Plant::prevState()
   * @brief Transitions the plant to the previous state.
   */
  void prevState();
  /** @fn void Plant::setCareStrategy(CareStrategy* s)
   * @brief Sets the care strategy for the plant.
   * @param s A pointer to the CareStrategy to set.
  */
  void setCareStrategy(CareStrategy* s);//added this for the Strategy design pattern
  /** @fn void Plant::applyCare()
   * @brief Applies the care strategy to the plant.
   */
  void applyCare();
  /** @fn void Plant::print()
   * @brief Prints the details of the plant.
   */
  virtual void print();
  /** @fn void Plant::addCust(Customer *customer)
   * @brief Associates a customer with the plant.
   * @param customer A pointer to the Customer to associate with the plant.
   */
  void addCust(Customer *customer);
  /** @fn PlantMemento* Plant::createPlantMemento()
   * @brief Creates a memento of the plant's current state.
   * @return A pointer to the newly created PlantMemento.
   */
  PlantMemento *createPlantMemento();
  /** @fn void Plant::setPlantMemento(PlantMemento *memento)
   * @brief Restores the plant's state from a memento.
   * @param memento A pointer to the PlantMemento to restore from.
   */
  void setPlantMemento(PlantMemento *memento);
  
  virtual Plant *clone() = 0;

protected:
  /** @fn Plant::Plant(Plant &toCopy)
   * @brief Copy constructor for the Plant class.
   * @param toCopy A reference to the Plant object to be copied.
   */
  Plant(Plant &toCopy);
};

#endif
