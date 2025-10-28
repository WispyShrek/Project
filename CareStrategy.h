#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

#include <string>
class CareStrategy {
protected:
  std::string strategyName;

public:
  virtual void applyCare() = 0;
  std::string getStrategyName();
  CareStrategy();
  ~CareStrategy();
};

#endif
