#include "SprinklersOff.h"

SprinklersOff::SprinklersOff() : sprinklers(new Sprinkler) {}

void SprinklersOff::execute() {
	sprinklers->turnOff();
}
 

#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("SprinklersOff: Test SprinklersOff class methods") {
	SprinklersOff sprinklersOffCommand;

	// Test execute method
	sprinklersOffCommand.execute(); // Should turn off the sprinklers (prints "Sprinkler: OFF")
}
#endif