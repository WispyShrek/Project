#ifndef COMPOSITEGARDEN_H
#define COMPOSITEGARDEN_H
#include "Garden.h"
#include <list>

class CompositeGarden : public Garden {
  public:
    CompositeGarden();
    ~CompositeGarden();
    void addGarden(Garden *g) override;
    void removeGarden(Garden *g) override;
    void print() override;
    void printChild(int param) override;
  private:
    std::list<Garden*> gardens;


};

#endif
