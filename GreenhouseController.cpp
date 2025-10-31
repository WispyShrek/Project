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


#ifdef ENABLE_DOCTESTS
#include "doctest.h"
class MockCommand : public Command {
public:
    bool executed;
    MockCommand() : executed(false) {}
    void execute() override {
        executed = true;
    }
};
TEST_CASE("GreenhouseController: Test Command Execution") {
    GreenhouseController controller;

    MockCommand* sprinklerOn = new MockCommand();
    MockCommand* sprinklerOff = new MockCommand();
    MockCommand* lightOn = new MockCommand();
    MockCommand* lightOff = new MockCommand();

    controller.setSprinklerCommands(sprinklerOn, sprinklerOff);
    controller.setLightCommands(lightOn, lightOff);

    controller.flipUpSprinklers();
    REQUIRE(sprinklerOn->executed == true);
    REQUIRE(sprinklerOff->executed == false);

    controller.flipDownSprinklers();
    REQUIRE(sprinklerOff->executed == true);

    controller.flipUpLights();
    REQUIRE(lightOn->executed == true);
    REQUIRE(lightOff->executed == false);

    controller.flipDownLights();
    REQUIRE(lightOff->executed == true);

    delete sprinklerOn;
    delete sprinklerOff;
    delete lightOn;
    delete lightOff;
}
TEST_CASE("GreenhouseController: Test Unset Commands") {
    GreenhouseController controller;

    // Capture standard error output
    std::streambuf* originalCerr = std::cerr.rdbuf();
    std::ostringstream capturedCerr;
    std::cerr.rdbuf(capturedCerr.rdbuf());

    controller.flipUpSprinklers();
    REQUIRE(capturedCerr.str().find("SprinklersUpCommand not set") != std::string::npos);

    capturedCerr.str(""); // Clear captured output
    controller.flipDownSprinklers();
    REQUIRE(capturedCerr.str().find("SprinklersdownCommand not set") != std::string::npos);

    capturedCerr.str(""); // Clear captured output
    controller.flipUpLights();
    REQUIRE(capturedCerr.str().find("lightUpCommand not set") != std::string::npos);

    capturedCerr.str(""); // Clear captured output
    controller.flipDownLights();
    REQUIRE(capturedCerr.str().find("lightDownCommand not set") != std::string::npos);

    // Restore original cerr buffer
    std::cerr.rdbuf(originalCerr);
}
#endif