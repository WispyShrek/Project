#include "Cactus.h"

Cactus::Cactus(){
    this->strategy = new AridCare();
    this->price = 50;
}

std::string Cactus::getName(){
    return "Cactus";
}

Cactus *Cactus::clone(){
    return new Cactus(*this);
}

void Cactus::print(){
  std::string sprite;
  sprite.append("\x1B[38;5;34m *");

  sprite.append("\x1B[38;5;28m|");
  std::cout << sprite;
}

double Cactus::getPrice(){
    return price;
}

Cactus::Cactus(Cactus &toCopy) : Plant(toCopy){
    this->price = toCopy.price;
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("Cactus: Test Cactus class methods") {
  Cactus cactus;

  // Test getName method
  REQUIRE(cactus.getName() == "Cactus");

  // Test getPrice method
  REQUIRE(cactus.getPrice() == 50);

  // Test clone method
  Cactus *clonedCactus = cactus.clone();
  REQUIRE(clonedCactus != nullptr);
  REQUIRE(clonedCactus->getName() == "Cactus");
  REQUIRE(clonedCactus->getPrice() == 50);
  delete clonedCactus;

  // Test print method (just ensure it runs without error)
  cactus.print();
}
#endif