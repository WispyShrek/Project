#include "GreenhouseController.h"

GreenhouseController::GreenhouseController()
: upCommand(new SprinklersOn()),      // default to Sprinklers
  downCommand(new SprinklersOff()) {}

GreenhouseController::~GreenhouseController() {
    delete upCommand;
    delete downCommand;
    upCommand = downCommand = nullptr;
}

void GreenhouseController::flipUp() {
    if (upCommand) upCommand->execute();
}

void GreenhouseController::flipDown() {
    if (downCommand) downCommand->execute();
}