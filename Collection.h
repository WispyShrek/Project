#ifndef COLLECTION_H
#define COLLECTION_H
#include "Iterator.h"
template <typename T>

class Collection {
public:
  // the methods used for the iterator DP, the abstract methods.
  virtual Iterator<T> *CreateIterator() = 0;
  virtual bool addItem(T item) = 0;
  virtual void removeItem(T item) = 0;
};

#endif
