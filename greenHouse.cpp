#include "greenHouse.h"
#include "GreenhouseController.h"

void greenHouse::powerSystem() {
    GreenhouseController controller;
    controller.flipUp();     // e.g. [Sprinkler] ON
    controller.flipDown();   // e.g. [Sprinkler] OFF
}
 