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
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include "GreenhouseController.h"
#include "Command.h"

struct LogCommand : public Command {
    std::string name;
    std::vector<std::string>* log;
    LogCommand(std::string n, std::vector<std::string>& L) : name(std::move(n)), log(&L) {}
    void execute() override { log->push_back(name); }
};

TEST_CASE("GreenhouseController null-guards when commands are not set") {
    GreenhouseController ctl;
    std::ostringstream cap;
    auto* old = std::cerr.rdbuf(cap.rdbuf());
    ctl.flipUpSprinklers();
    ctl.flipUpLights();
    ctl.flipDownSprinklers();
    ctl.flipDownLights();
    std::cerr.rdbuf(old);
    std::string out = cap.str();
    CHECK(out.find("SprinklersUpCommand not set") != std::string::npos);
    CHECK(out.find("lightUpCommand not set") != std::string::npos);
    CHECK(out.find("SprinklersdownCommand not set") != std::string::npos);
    CHECK(out.find("lightDownCommand not set") != std::string::npos);
}

TEST_CASE("GreenhouseController executes wired commands in order") {
    GreenhouseController ctl;
    std::vector<std::string> log;
    auto* sprOn  = new LogCommand("spr_on", log);
    auto* sprOff = new LogCommand("spr_off", log);
    auto* lOn    = new LogCommand("light_on", log);
    auto* lOff   = new LogCommand("light_off", log);
    ctl.setSprinklerCommands(sprOn, sprOff);
    ctl.setLightCommands(lOn, lOff);
    ctl.flipUpSprinklers();
    ctl.flipUpLights();
    ctl.flipDownSprinklers();
    ctl.flipDownLights();
    std::vector<std::string> expected{"spr_on","light_on","spr_off","light_off"};
    CHECK(log == expected);
    delete sprOn; delete sprOff; delete lOn; delete lOff;
}
#endif
