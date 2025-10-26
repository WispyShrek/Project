#include "SprinklersOff.h"

SprinklersOff::SprinklersOff() : sprinklers(new Sprinkler) {}

void SprinklersOff::execute() {
	sprinklers->turnOff();
}
 