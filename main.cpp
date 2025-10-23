#include <iostream>
#include "CompositeGarden.h"
#include "Garden.h"
#include "Plant.h"
#include "Rose.h"
#include "Tulip.h"
#include "Lavender.h"

int main() {
  using std::cout;
  using std::endl;

  // build composite tree
  CompositeGarden *root = new CompositeGarden();
  CompositeGarden *section1 = new CompositeGarden();
  CompositeGarden *section2 = new CompositeGarden();

  // leaf nodes (adjust constructors if these classes require parameters)
  Rose *rose1 = new Rose();
  Tulip *tulip1 = new Tulip();
  Lavender *lav1 = new Lavender();

  // assemble
  root->addGarden(section1);
  root->addGarden(rose1);        // root has a direct leaf
  section1->addGarden(tulip1);
  section1->addGarden(lav1);
  root->addGarden(section2);     // empty section2 for testing

  cout << "Print entire garden (root):" << endl;
  root->print();                 // should traverse and print children

  cout << "\nPrint root child 0 (section1):" << endl;
  root->printChild(0);           // prints section1 subtree

  cout << "\nPrint section1 child 1 (lavender):" << endl;
  section1->printChild(1);       // prints lavender

  // remove lavender from section1 (does not delete pointer in current implementation)
  cout << "\nRemoving lavender from section1 and printing section1:" << endl;
  section1->removeGarden(lav1);
  section1->print();

  // clean up: delete root -> CompositeGarden::~CompositeGarden will delete owned children
  cout << "\nDeleting root (will delete owned children):" << endl;
  delete root;

  cout << "Done." << endl;
  return 0;
}
