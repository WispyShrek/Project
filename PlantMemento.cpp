#include "PlantMemento.h"

PlantMemento::PlantMemento() : currState(nullptr) {}

PlantMemento::PlantMemento(PlantState* state) {
    currState = state ? state->clone() : nullptr;
}

PlantMemento::~PlantMemento() {
    delete currState;
}

PlantState* PlantMemento::getState() const {
    // Return a CLONE of the internal state.
    // The Plant (Originator) will take ownership of this new copy.
    return currState ? currState->clone() : nullptr;
}

void PlantMemento::setState(PlantState* state) {
    delete currState;
    currState = state ? state->clone() : nullptr;
}

#ifdef ENABLE_DOCTESTS
#include "doctest.h"
#include "Sprout.h"
#include "Flowering.h"
#include "Mature.h"

TEST_SUITE("PlantMemento") {
    TEST_CASE("Default constructor creates a null state") {
        PlantMemento memento;
        CHECK(memento.getState() == nullptr);
    }

    TEST_CASE("Constructor with a valid state creates a clone") {
        PlantState* originalState = new Sprout();
        PlantMemento memento(originalState);

        PlantState* restoredState = memento.getState();

        CHECK(restoredState != nullptr);
        CHECK(dynamic_cast<Sprout*>(restoredState) != nullptr);
        CHECK(restoredState != originalState); // Should be a clone, not the same instance

        delete originalState;
        delete restoredState;
    }

    TEST_CASE("setState correctly clones and replaces the state") {
        PlantMemento memento;
        PlantState* sproutState = new Sprout();
        memento.setState(sproutState);

        PlantState* restoredSprout = memento.getState();
        CHECK(restoredSprout != nullptr);
        CHECK(dynamic_cast<Sprout*>(restoredSprout) != nullptr);
        CHECK(restoredSprout != sproutState);

        // Now, set a new state
        PlantState* floweringState = new Flowering();
        memento.setState(floweringState);

        PlantState* restoredFlowering = memento.getState();
        CHECK(restoredFlowering != nullptr);
        CHECK(dynamic_cast<Flowering*>(restoredFlowering) != nullptr);
        CHECK(dynamic_cast<Sprout*>(restoredFlowering) == nullptr); // Should no longer be a Sprout

        // Cleanup
        delete sproutState;
        delete restoredSprout;
        delete floweringState;
        delete restoredFlowering;
    }

    TEST_CASE("Setting and getting a null state") {
        PlantState* matureState = new Mature();
        PlantMemento memento(matureState); // Start with a valid state

        memento.setState(nullptr); // Set to null
        CHECK(memento.getState() == nullptr);

        delete matureState;
    }
}
#endif
