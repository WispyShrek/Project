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

  // -----------------------
  // Inventory removeItem tests
  // -----------------------
  cout << "\nInventory removeItem test (remove existing 'Tulip seeds'):" << endl;
  inv.removeItem("Tulip seeds");
  Iterator<std::string> *it2 = inv.CreateIterator();
  if (it2) {
    for (it2->first(); !it2->isDone(); it2->next()) {
      cout << " - " << it2->currItem() << endl;
    }
    delete it2;
  }

  cout << "\nInventory removeItem test (remove non-existent 'Fake item'):" << endl;
  inv.removeItem("Fake item"); // should be a no-op
  Iterator<std::string> *it3 = inv.CreateIterator();
  if (it3) {
    for (it3->first(); !it3->isDone(); it3->next()) {
      cout << " - " << it3->currItem() << endl;
    }
    delete it3;
  }

  cout << "\nInventory removeItem test (remove first 'Rose pot'):" << endl;
  inv.removeItem("Rose pot"); // remove first element
  Iterator<std::string> *it4 = inv.CreateIterator();
  if (it4) {
    for (it4->first(); !it4->isDone(); it4->next()) {
      cout << " - " << it4->currItem() << endl;
    }
    delete it4;
  }

  // cleanup composite (CompositeGarden destructor should delete owned children)
  cout << "\nDeleting root (will delete owned children):" << endl;
  delete root;

  cout << "Done." << endl;
  return 0;
}
