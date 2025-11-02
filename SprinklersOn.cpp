#include "SprinklersOn.h"

SprinklersOn::SprinklersOn() : sprinklers(new Sprinkler) {}

void SprinklersOn::execute() {
	sprinklers->turnOn();
}
 


#ifdef ENABLE_DOCTESTS
#include "doctest.h"

TEST_CASE("SprinklersOn: Test SprinklersOn class methods") {
	SprinklersOn sprinklersOnCommand;

	// Test execute method
	sprinklersOnCommand.execute(); // Should turn on the sprinklers (prints "Sprinkler: ON")
}
#endif