#include "CompositeGarden.h"

CompositeGarden::CompositeGarden(){
  //default constructor
}

//adds child to list
void CompositeGarden::addGarden(Garden *g){
  gardens.push_back(g);
}

//removes child from list
void CompositeGarden::removeGarden(Garden *g){
  gardens.remove(g);
  delete g;
}

//prints all children
void CompositeGarden::print(){
  for(std::list<Garden*>::iterator it = gardens.begin(); it!= gardens.end(); ++it){
    (*it)->print();
  }
}

//prints child at given index
void CompositeGarden::printChild(int param){
  std::list<Garden*>::iterator it = gardens.begin();
  std::advance(it, param);
  (*it)->print();
}

//destructor
//deletes all children in the list
CompositeGarden::~CompositeGarden(){
  for(std::list<Garden*>::iterator it = gardens.begin(); it != gardens.end(); ++it){
    delete *it;
  }
}
