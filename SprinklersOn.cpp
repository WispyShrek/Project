#include "SprinklersOn.h"

SprinklersOn::SprinklersOn() : sprinklers(new Sprinkler) {}

void SprinklersOn::execute() {
	sprinklers->turnOn();
}
 