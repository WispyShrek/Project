#include "GreenhouseController.h"

#include <iostream>

GreenhouseController::GreenhouseController(): 
    SprinklersUpCommand(nullptr),
    SprinklersdownCommand(nullptr),
    lightUpCommand(nullptr),
    lightDownCommand(nullptr)
{}

GreenhouseController::~GreenhouseController() {
}

void GreenhouseController::setSprinklerCommands(Command* on, Command* off) {
    SprinklersUpCommand   = on;
    SprinklersdownCommand = off;
}

void GreenhouseController::setLightCommands(Command* on, Command* off) {
    lightUpCommand   = on;
    lightDownCommand = off;
}

void GreenhouseController::flipUpSprinklers() {
    if (!SprinklersUpCommand) { std::cerr << "[Controller] SprinklersUpCommand not set\n"; return; }
    SprinklersUpCommand->execute();
}
void GreenhouseController::flipDownSprinklers() {
    if (!SprinklersdownCommand) { std::cerr << "[Controller] SprinklersdownCommand not set\n"; return; }
    SprinklersdownCommand->execute();
}
void GreenhouseController::flipUpLights() {
    if (!lightUpCommand) { std::cerr << "[Controller] lightUpCommand not set\n"; return; }
    lightUpCommand->execute();
}
void GreenhouseController::flipDownLights() {
    if (!lightDownCommand) { std::cerr << "[Controller] lightDownCommand not set\n"; return; }
    lightDownCommand->execute();
}