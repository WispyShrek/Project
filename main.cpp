#include <iostream>
#include <vector>
#include "CompositeGarden.h"
#include "Garden.h"
#include "Plant.h"
#include "Rose.h"
#include "Tulip.h"
#include "Lavender.h"
#include "Inventory.h"
#include "Iterator.h"
#include "GardenIterator.h"

int main() {
  using std::cout;
  using std::endl;

  // -----------------------
  // Composite pattern test
  // -----------------------
  CompositeGarden *root = new CompositeGarden();
  CompositeGarden *section1 = new CompositeGarden();
  CompositeGarden *section2 = new CompositeGarden();

  Rose *rose1 = new Rose();
  Tulip *tulip1 = new Tulip();
  Lavender *lav1 = new Lavender();

  // assemble tree
  root->addGarden(section1);
  root->addGarden(rose1);        // root has a direct leaf
  section1->addGarden(tulip1);
  section1->addGarden(lav1);
  root->addGarden(section2);     // empty section2 for testing

  cout << "Print entire garden (root):" << endl;
  root->print();                 // traverse & print children

  cout << "\nPrint root child 0 (section1):" << endl;
  root->printChild(0);           // prints section1 subtree

  cout << "\nPrint section1 child 1 (lavender):" << endl;
  section1->printChild(1);       // prints lavender

  // -----------------------
  // Garden iterator test
  // -----------------------
  {
    // iterate over root-level children we added
    std::vector<Garden*> rootChildren;
    rootChildren.push_back(section1);
    rootChildren.push_back(rose1);
    rootChildren.push_back(section2);

    Iterator<Garden*> *git = new GardenIterator(rootChildren);
    cout << "\nGarden iterator (root-level children):" << endl;
    for (git->first(); !git->isDone(); git->next()) {
      Garden *g = git->currItem();
      if (g) g->print();
    }
    delete git;
  }

  {
    // iterate over section1's children
    std::vector<Garden*> sec1Children;
    sec1Children.push_back(tulip1);
    sec1Children.push_back(lav1);

    Iterator<Garden*> *sit = new GardenIterator(sec1Children);
    cout << "\nGarden iterator (section1 children):" << endl;
    for (sit->first(); !sit->isDone(); sit->next()) {
      Garden *g = sit->currItem();
      if (g) g->print();
    }
    delete sit;
  }

  cout << "\nRemoving lavender from section1 and printing section1:" << endl;
  section1->removeGarden(lav1);
  section1->print();

  // -----------------------
  // Iterator (Inventory) test
  // -----------------------
  cout << "\nInventory iterator test:" << endl;
  Inventory inv;
  inv.addItem("Rose pot");
  inv.addItem("Tulip seeds");
  inv.addItem("Lavender bundle");
  inv.addItem("Water can");

  Iterator<std::string> *it = inv.CreateIterator();
  if (it) {
    cout << "Forward iteration:" << endl;
    for (it->first(); !it->isDone(); it->next()) {
      cout << " - " << it->currItem() << endl;
    }

    // test prev / random access-ish behaviour
    cout << "Test next/prev:" << endl;
    it->first();
    it->next(); // move to second item
    if (!it->isDone()) cout << " current: " << it->currItem() << endl;
    it->prev();
    if (!it->isDone()) cout << " after prev: " << it->currItem() << endl;

    delete it;
  } else {
    cout << "CreateIterator returned nullptr" << endl;
  }

  // cleanup composite (CompositeGarden destructor should delete owned children)
  cout << "\nDeleting root (will delete owned children):" << endl;
  delete root;

  cout << "Done." << endl;
  return 0;
}
