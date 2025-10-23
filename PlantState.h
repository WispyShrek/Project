#ifndef PLANTSTATE_H
#define PLANTSTATE_H
class Plant;

class PlantState {
public:
  virtual void next(Plant *context) = 0;
  virtual void prev(Plant *context) = 0;
};

#endif
