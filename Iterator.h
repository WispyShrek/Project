#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>

class Iterator {
public:
  // abstract methods
  virtual ~Iterator() {};
  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() = 0;
  virtual T currItem() = 0;
  virtual void setCurrItem(T) = 0;
  virtual void prev() = 0;
};

#endif
