#ifndef COMPOSITEGARDEN_H
#define COMPOSITEGARDEN_H
#include "Garden.h"

class CompositeGarden : public Garden {
public:
  Garden *children;
  CompositeGarden();
  void addGarden(Garden *g);
  void removeGarden(Garden *g);
  void print();
};

#endif
