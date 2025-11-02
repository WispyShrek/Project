/**
 * @file CareStrategy.h
 * @brief Defines the abstract base class for all care strategies in the Strategy design pattern.
 */
#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

#include <string>

/**
 * @class CareStrategy
 * @brief An abstract base class for different plant care strategies.
 *
 * This class serves as the 'Strategy' in the Strategy design pattern. It defines
 * a common interface ("applyCare") that all concrete care strategies must implement.
 * The "Plant" class (the 'Context') will use a pointer to a "CareStrategy" object
 * to apply a specific care routine without being coupled to the concrete strategy's
 * implementation.
 */
class CareStrategy {
protected:
  /**
   * @var std::string strategyName
   * @brief The name of the concrete care strategy.
   */
  std::string strategyName;

public:
  /**
   * @brief Pure virtual method to apply a specific care routine.
   *
   * This is the core method of the Strategy pattern. Concrete subclasses must
   * override this method to provide the specific algorithm for a care strategy.
   */
  virtual void applyCare() = 0;
  /**
   * @brief Gets the name of the strategy.
   * @return A string representing the name of the concrete strategy.
   */
  virtual std::string getStrategyName();
  /**
   * @brief Default constructor for CareStrategy.
   */
  CareStrategy();
  /**
   * @brief Virtual destructor.
   *
   * Ensures that destructors of derived concrete strategy classes are called
   * correctly when a strategy object is deleted through a base class pointer.
   */
  virtual ~CareStrategy();
};

#endif
