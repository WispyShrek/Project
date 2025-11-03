#include <iostream>
#include <vector>
#include "Garden.h"
#include "Plant.h"
#include "Rose.h"
#include "Tulip.h"
#include "Lavender.h"
#include "Lily.h"
#include "Inventory.h"
#include "Iterator.h"
#include "PlantIterator.h"
#include "GardenIterator.h"
#include "GreenhouseIterator.h"
#include "LilyCreator.h"
#include "RoseCreator.h"
#include "TulipCreator.h"
#include "LavenderCreator.h"
#include "greenHouse.h"
#include "GreenhouseController.h"
#include "PlantCaretakerCreator.h"
#include "CustomerAssistantCreator.h"
#include "Sunny.h"
#include "Nursery.h"
#include "PlantCaretaker.h"
#include "CustomerAssistant.h"
#include "CareStrategy.h"
#include "SunnyCare.h"
#include "ShadyCare.h"
#include "PartialSunCare.h"
#include "Plant.h"
#include "EFT.h"
#include "Card.h"
#include "Cash.h"
#include "PaymentStrategy.h"
#include "Transaction.h"
#include "PlantCaretaker.h"
#include "Caretaker.h"
#include "PlantMemento.h"
#include "FussyCust.h"

int main() {
    using std::cout;
    using std::endl;

    // === Grid-based iterator tests (Garden + PlantIterator) ===
    cout << "\n=== Grid-based Garden/PlantIterator tests ===\n";
    Garden* g = new Sunny();

    Plant* g_p1 = new Rose();
    Plant* g_p2 = new Lily();
    Plant* g_p3 = new Lavender();
    Plant* g_p4 = new Tulip();

    // Place at positions, then auto-fill first free
    g->addItem(g_p1, 0, 0);
    g->addItem(g_p2, 0, 2);
    g->addItem(g_p3);            // should take (0,1)
    g->addItem(g_p4, 2, 2);

    Iterator<Plant*>* git = g->CreateIterator();
    git->first();
    cout << "Garden iteration (row-major, skipping nulls):\n";
    while (!git->isDone()) {
        if (auto* p = git->currItem()) p->print();
        git->next();
    }

    cout << "\nGarden removeItem (creates hole) and auto-fill earliest hole:\n";
    g->removeItem(g_p3);         // hole at (0,1)
    Plant* g_p5 = new Rose();
    g->addItem(g_p5);            // fills (0,1)
    git->first();
    while (!git->isDone()) {
        if (auto* p = git->currItem()) p->print();
        git->next();
    }

    cout << "\nGarden PlantIterator prev() from done goes to last:\n";
    git->first();
    while (!git->isDone()) git->next();
    git->prev();
    if (auto* p = git->currItem()) p->print();

    delete git; // Garden owns remaining plants
    delete g_p3; // removed earlier
    delete g;

    // === Grid-based iterator tests (greenHouse + PlantIterator) ===
    cout << "\n=== Grid-based greenHouse/PlantIterator tests ===\n";
    greenHouse gh;

    // Explicit placement plus auto-fill, same logic as Garden
    Plant* h1 = new Rose();
    Plant* h2 = new Tulip();
    Plant* h3 = new Lavender();
    Plant* h4 = new Lily();

    gh.addItem(h1, 0, 0);   // place at (0,0)
    gh.addItem(h2, 0, 2);   // place at (0,2)
    gh.addItem(h3);         // auto-fill -> (0,1)
    gh.addItem(h4, 2, 2);   // place at (2,2)

    Iterator<Plant*>* hit = gh.CreateIterator();
    hit->first();
    cout << "greenHouse iteration (row-major, skipping nulls):\n";
    while (!hit->isDone()) {
        if (auto* p = hit->currItem()) p->print();
        hit->next();
    }

    cout << "\ngreenHouse removeItem (skip hole), then prev() from done:\n";
    gh.removeItem(h3); // create hole at (0,1)
    hit->first();
    while (!hit->isDone()) {
        if (auto* p = hit->currItem()) p->print();
        hit->next();
    }
    hit->prev(); // from done -> last non-null
    if (auto* p = hit->currItem()) p->print();

    // Capacity quick check: fill to 7 and ensure we don't exceed
    {
        // Currently we have h1 at (0,0), h2 at (0,2), h4 at (2,2)
        // Add 4 more
        std::vector<Plant*> extras;
        for (int i = 0; i < 4; ++i) {
            auto* np = new Rose();
            extras.push_back(np);
            gh.addItem(np);
        }
        // Attempt 8th (should be rejected; message printed)
        Plant* overflow = new Rose();
        gh.addItem(overflow);
        // Clean up overflow (not added, so not owned by gh)
        delete overflow;

        // Clean up: remove everything we manually own from gh before scope ends
        for (auto* p : extras) gh.removeItem(p);
        for (auto* p : extras) delete p;
    }

    delete hit;
    // Remove and delete the ones we added that were removed from gh
    gh.removeItem(h1); delete h1;
    gh.removeItem(h2); delete h2;
    gh.removeItem(h4); delete h4;

    // ...existing demo/tests...
    cout << "\n=== Testing Garden Iterator ===\n" << endl;
    Garden* garden = new Sunny();
    
    // Add plants
    garden->addItem(new Rose());
    garden->addItem(new Tulip());
    garden->addItem(new Lavender());
    garden->addItem(new Lily());
    garden->addItem(new Rose());
    garden->addItem(new Tulip());

    std::cout << "Added 6 plants to the garden." << std::endl;

    
    Iterator<Plant*>* gardenIt = garden->CreateIterator();
    
    cout << "Testing first() and currItem():" << endl;
    gardenIt->first();
    if (Plant* p = gardenIt->currItem()) {
        p->print();
    }
    
    cout << "\nTesting next() and currItem():" << endl;
    gardenIt->next();
    if (Plant* p = gardenIt->currItem()) {
        p->print();
    }
    
    cout << "\nTesting prev() and currItem():" << endl;
    gardenIt->prev();
    if (Plant* p = gardenIt->currItem()) {
        p->print();
    }
    
    cout << "\nTesting isDone() at valid position:" << endl;
    cout << "isDone: " << (gardenIt->isDone() ? "true" : "false") << endl;
    
    while (!gardenIt->isDone()) {
        gardenIt->next();
    }

    cout << "\nTesting isDone() after moving past end:" << endl;
    cout << "isDone: " << (gardenIt->isDone() ? "true" : "false") << endl;
    
    delete gardenIt;
    
    cout << "\n=== Testing Inventory Iterator ===\n" << endl;
    Inventory inventory;
    
    inventory.addItem("Plant Food");
    inventory.addItem("Watering Can");
    inventory.addItem("Garden Shears");
    
    Iterator<std::string>* invIt = inventory.CreateIterator();
    
    cout << "Testing first() and currItem():" << endl;
    invIt->first();
    cout << invIt->currItem() << endl;
    
    cout << "\nTesting next() and currItem():" << endl;
    invIt->next();
    cout << invIt->currItem() << endl;
    
    cout << "\nTesting prev() and currItem():" << endl;
    invIt->prev();
    cout << invIt->currItem() << endl;
    
    cout << "\nTesting isDone() at valid position:" << endl;
    cout << "isDone: " << (invIt->isDone() ? "true" : "false") << endl;
    
    // Move to end
    invIt->next();
    invIt->next();
    invIt->next();
    
    cout << "\nTesting isDone() after moving past end:" << endl;
    cout << "isDone: " << (invIt->isDone() ? "true" : "false") << endl;
    
    delete invIt;
    delete garden;
    
    cout << "\nDone." << endl;

    // ===== Test Lily =====
    {
        std::cout << "\n=== LilyCreator ===\n";
        LilyCreator maker;
        Plant* a = maker.createPlant();                         // Factory Method
        std::cout << "created: " << a->getState() << "\n";

        Plant* b = a->clone();                                  // Prototype
        std::cout << "cloned : " << b->getState() << "\n";

    }

    // ===== Test Rose =====
    {
        std::cout << "\n=== RoseCreator ===\n";
        RoseCreator maker;
        Plant* a = maker.createPlant();
        std::cout << "created: " << a->getState() << "\n";

enum class MenuState {
  MAIN,
  PLANT,
  WATER,
  HARVEST,
  GARDENS,
  STAFFHIRE,
  STAFF,
  CHOICE,
  GREENHOUSES
};

    }

    // ===== Test Tulip =====
    {
        std::cout << "\n=== TulipCreator ===\n";
        TulipCreator maker;
        Plant* a = maker.createPlant();
        std::cout << "created: " << a->getState() << "\n";

        Plant* b = a->clone();
        std::cout << "cloned : " << b->getState() << "\n";

int main() {
  // game initialization
  // we have a fixed number of gardens in the nursery
  Nursery &nursery = Nursery::instance();
  Garden *sunny1 = new Sunny();
  Garden *sunny2 = new Sunny();
  Garden *partial1 = new PartialSun();
  Garden *partial2 = new PartialSun();
  Garden *shady1 = new Shady();
  Garden *shady2 = new Shady();
  greenHouse *g1 = new greenHouse();
  greenHouse *g2 = new greenHouse();
  greenHouse *g3 = new greenHouse();
  nursery.addGarden(sunny1);
  nursery.addGarden(sunny2);
  nursery.addGarden(partial1);
  nursery.addGarden(partial2);
  nursery.addGarden(shady1);
  nursery.addGarden(shady2);
  // vector contains all of the staff members that can be hired
  CustomerAssistantCreator assitantCreator = CustomerAssistantCreator();
  PlantCaretakerCreator caretakerCreator = PlantCaretakerCreator();
  Staff *staffCustomerPete = assitantCreator.createStaff();
  Staff *staffCustomerLizzy = assitantCreator.createStaff();
  Staff *staffCaretakerHolly = caretakerCreator.createStaff();
  Staff *staffCaretakerAlly = caretakerCreator.createStaff();
  Staff *staffCaretakerRyan = caretakerCreator.createStaff();
  Staff *staffCaretakerJohn = caretakerCreator.createStaff();
  staffCustomerPete->setName("Pete");
  staffCustomerPete->setDescription("My name is Pete!\nI will help you sell "
                                    "plants \nto customers with a smile.");
  staffCustomerLizzy->setName("Lizzy");
  staffCustomerLizzy->setDescription("My name is Lizzy!\nI can handle customer "
                                     "interactions \nto help you make sales.");
  staffCaretakerRyan->setName("Ryan");
  staffCaretakerRyan->setDescription(
      "Ryan's the name!\nI will help you keep your plants \nin good shape.");
  staffCaretakerHolly->setName("Holly");
  staffCaretakerHolly->setDescription(
      "Holly here!\nI have the greenest thumbs in town.");
  staffCaretakerAlly->setName("Ally");
  staffCaretakerAlly->setDescription("I'm Ally!\nPlants need to receive the "
                                     "best \ncare possible.\nI won't let "
                                     "you down!");
  staffCaretakerJohn->setName("John");
  staffCaretakerJohn->setDescription(
      "John reporting for duty!\nAin't no plants gonna die \non my watch.");

  vector<Staff *> toHire = vector<Staff *>();
  toHire.push_back(staffCaretakerAlly);
  toHire.push_back(staffCaretakerHolly);
  toHire.push_back(staffCaretakerJohn);
  toHire.push_back(staffCaretakerRyan);
  toHire.push_back(staffCustomerLizzy);
  toHire.push_back(staffCustomerPete);
  // plants that can be bought initialized by the creators
  TulipCreator tulip = TulipCreator();
  LavenderCreator lavender = LavenderCreator();
  RoseCreator rose = RoseCreator();
  LilyCreator lily = LilyCreator();
  Plant *dollyTulip = tulip.createPlant();
  Plant *dollyLavender = lavender.createPlant();
  Plant *dollyRose = rose.createPlant();
  Plant *dollyLily = lily.createPlant();

  // all plants bought should be sprouts
  PlantState *sprout = new Sprout();
  dollyTulip->setState(sprout->clone());
  dollyLavender->setState(sprout->clone());
  dollyLily->setState(sprout->clone());
  dollyRose->setState(sprout->clone());
  // add plants to shop
  vector<Plant *> shopPlants = vector<Plant *>();
  shopPlants.push_back(dollyLavender);
  shopPlants.push_back(dollyRose);
  shopPlants.push_back(dollyLily);
  shopPlants.push_back(dollyTulip);

  // gui initialization
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  nodelay(stdscr, TRUE);
  start_color();
  use_default_colors();

  init_pair(1, COLOR_GREEN, -1);
  init_pair(2, COLOR_CYAN, -1);
  init_pair(3, COLOR_YELLOW, -1);
  init_pair(4, COLOR_MAGENTA, -1);

  int height, width;
  getmaxyx(stdscr, height, width);

  int info_width = width / 4;
  int main_width = width - info_width;
  int menu_height = 5;
  int garden_height = height - menu_height;

  WINDOW *garden_win = create_newwin(garden_height, main_width, 0, 0, "Garden");
  WINDOW *menu_win =
      create_newwin(menu_height, main_width, garden_height, 0, "Menu");
  WINDOW *info_win =
      create_newwin(height, info_width, 0, main_width, "Nursery Info");

  PANEL *garden_panel = new_panel(garden_win);
  PANEL *menu_panel = new_panel(menu_win);
  PANEL *info_panel = new_panel(info_win);

  std::vector<std::string> main_menu = {"Plant Seed",     "Care for Plants",
                                        "Harvest Plants", "Hire Staff",
                                        "Assign Staff",   "Exit"};
  std::vector<std::string> choice_menu = {"Plant in Garden",
                                          "Plant in Greenhouse", "Back"};
  std::vector<std::string> plant_menu = std::vector<std::string>();
  for (auto plants : shopPlants) {
    plant_menu.push_back(plants->getName());
  }
  plant_menu.push_back("Back");
  vector<std::string> hire_menu;
  for (auto staff : toHire) {
    hire_menu.push_back(staff->getName());
  }
  hire_menu.push_back("Back");
  std::vector<std::string> staff_menu;
  for (auto staff : nursery.getStaff()) {
    staff_menu.push_back(staff->getName());
  }
  staff_menu.push_back("Back");
  std::vector<std::string> garden_menu = {"G 1 (Sunny)",
                                          "G 2 (Sunny)",
                                          "G 3 (Partial sun)",
                                          "G 4 (Partial sun)",
                                          "G 5 (Shady)",
                                          "G 6 (Shady)",
                                          "Back"};
  std::vector<std::string> greenhouse_menu = {"Greenhouse 1", "Greenhouse 2",
                                              "Greenhouse 3", "Back"};
  std::vector<std::string> water_menu = {"Water All", "Water Selected", "Back"};
  std::vector<std::string> harvest_menu = {"Harvest All", "Harvest Mature Only",
                                           "Back"};

  // Hover descriptions for each item
  std::unordered_map<std::string, std::string> descriptions;

  descriptions.try_emplace("Plant Seed",
                           "Open submenu to plant different crops.");
  descriptions.try_emplace("Harvest Plants", "Open submenu to harvest crops.");
  descriptions.try_emplace(
      "Hire Staff",
      "Open submenu to hire \n customer assistants and plant caretakers.");
  descriptions.try_emplace("Assign Staff",
                           "Assign plant caretakers to gardens.");
  descriptions.try_emplace("Exit", "Leave the nursery Simulation.");
  descriptions.try_emplace("Back", "Return to main menu.");

  for (auto plants : shopPlants) {
    std::stringstream plantDesc;
    plantDesc << plants->getDescription();
    plantDesc << "\n Cost: R";
    plantDesc << std::setprecision(2) << plants->getPrice();
    descriptions.try_emplace(plants->getName(), plantDesc.str());
  }
  for (auto staff : toHire) {
    descriptions.try_emplace(staff->getName(), staff->getDescription());
  }

  int choice = 0;
  bool running = true;
  MenuState state = MenuState::MAIN;

  using clock = std::chrono::steady_clock;
  auto start_time = clock::now();
  int day = 1;

  const double real_day_seconds = 10.0 * 60.0;
  const double game_day_seconds = 24.0 * 60.0 * 60.0;
  const double time_scale = game_day_seconds / real_day_seconds;
  Plant *toAdd = nullptr;
  Staff *staffToAssign = nullptr;
  int prevHour = 0;
  // random events happening using mersenne twister
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> chance(0.0, 1.0);
  nursery.addToBalance(5000);
  bool careMenu = false;
  bool harvest = false;
  bool savePlant = false;

  while (running) {

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    auto now = clock::now();
    std::chrono::duration<double> elapsed = now - start_time;
    double game_seconds = elapsed.count() * time_scale;

    int total_game_seconds = static_cast<int>(game_seconds);
    day = 1 + (total_game_seconds / 86400);
    int day_seconds = total_game_seconds % 86400;
    int hour = (day_seconds / 3600) % 24;
    int minute = (day_seconds % 3600) / 60;

    std::string time_str = format_time(hour, minute);
    std::string phase = get_time_phase(hour);

    // --- Garden Panel ---
    werase(garden_win);
    box(garden_win, 0, 0);
    wattron(garden_win, COLOR_PAIR(1));
    mvwprintw(garden_win, 0, 2, " Garden ");
    wattroff(garden_win, COLOR_PAIR(1));
    print_with_ansi(garden_win, 4, 4, nursery.getGardens()[0]->print());
    print_with_ansi(garden_win, 4, 44, nursery.getGardens()[1]->print());
    print_with_ansi(garden_win, 4, 84, nursery.getGardens()[2]->print());
    print_with_ansi(garden_win, 18, 4, nursery.getGardens()[3]->print());
    print_with_ansi(garden_win, 18, 44, nursery.getGardens()[4]->print());
    print_with_ansi(garden_win, 18, 84, nursery.getGardens()[5]->print());
    // random events that have a chance to happen every hour in the daytime
    if (((phase == "Morning") || (phase == "Afternoon")) && (prevHour < hour)) {
      for (auto garden : nursery.getGardens()) {
        double roll = chance(gen);
        if (roll < 0.9) {
          garden->tick();
        }
      }
      prevHour = hour;
    }

    // --- Determine which menu is active ---
    const std::vector<std::string> *current_menu = nullptr;
    switch (state) {
    case MenuState::MAIN:
      current_menu = &main_menu;
      break;
    case MenuState::PLANT:
      current_menu = &plant_menu;
      break;
    case MenuState::WATER:
      current_menu = &garden_menu;
      break;
    case MenuState::HARVEST:
      current_menu = &garden_menu;
      break;
    case MenuState::STAFFHIRE:
      current_menu = &hire_menu;
      break;
    case MenuState::STAFF:
      current_menu = &staff_menu;
      break;
    case MenuState::GARDENS:
      current_menu = &garden_menu;
      break;
    case MenuState::CHOICE:
      current_menu = &choice_menu;
    }

    std::cout << "\nAll factory tests done.\n";

    Lily plant;  // starts in Sprout (from Plant::Plant())
    plant.print();

    std::cout << "start: " << plant.getState() << "\n";        // expect: Sprout
    plant.Plant::print();

    plant.applyCare();                                       
    std::cout << "after care: " << plant.getState() << "\n"; 
    plant.Plant::print();
    
    plant.applyCare();                                         // Flowering -> Mature
    std::cout << "after more care: " << plant.getState() << "\n"; // expect: Mature
    plant.Plant::print();

    plant.applyCare();                                      
    std::cout << "after care to Mature: " << plant.getState() << "\n";
    plant.Plant::print();

    std::cout << "All state tests done" << std::endl;



    std::cout << "== Direct controller test ==\n";
    {
        GreenhouseController ctl;   // defaults to SprinklersOn/Off

        std::cout << "Flip up:\n";
        ctl.flipUpSprinklers();               // expect: [Sprinkler] ON

        std::cout << "Flip down:\n";
        ctl.flipDownSprinklers();             // expect: [Sprinkler] OFF

        std::cout << "Flip up x2 then down:\n";
        ctl.flipUpSprinklers();               // [Sprinkler] ON
        ctl.flipUpSprinklers();               // [Sprinkler] ON (again)
        ctl.flipDownSprinklers();             // [Sprinkler] OFF

        
    } 
    std::cout << "\n== greenHouse::powerSystem() test ==\n";
    {
        greenHouse gh;
        gh.powerSystem();           // internally creates a controller and flips up/down
    }

    std::cout << "\nAll tests done.\n";


    std::cout << "== Staff factory test ==\n";

    PlantCaretakerCreator pcc;
    CustomerAssistantCreator cac;

    Staff* a = pcc.createStaff();    // Factory Method
    Staff* b = cac.createStaff();
    Customer* cust1 = new FussyCust();
    a->care();    a->update();    a->notify(cust1);
    b->care();    b->update();    b->notify(cust1);

    delete b; 
    delete a;

    std::cout << "Done.\n";
    // =========Singleton tests ==========

    std::cout << "=== Singleton/Nursery ===";

    Nursery& nursery1 = Nursery::instance();
    Nursery& nursery2 = Nursery::instance();

    std::cout << "Checking if both references are the same instance...\n";
    if (&nursery1 == &nursery2)
        std::cout << "PASS: Only one instance exists.\n";
    else
        std::cout << "FAIL: Multiple instances detected!\n";

    PlantCaretaker* caretaker = new PlantCaretaker();
    CustomerAssistant* assistant = new CustomerAssistant();

    nursery1.addStaff(caretaker);
    nursery1.addStaff(assistant);

    std::cout << "Added staff.\n";

    nursery1.addStaff(caretaker);


    // Add gardens
    Garden* garden1 = new Sunny();
    Garden* garden2 = new Sunny();
    nursery1.addGarden(garden1);
    nursery1.addGarden(garden2);

    std::cout << "Added gardens.\n";

    // Test remove
    nursery1.removeStaff(caretaker);
    nursery1.removeGarden(garden1);

    std::cout << "Removed one staff and one garden.\n";

    for (int i = 0; i < 5; ++i) {
        PlantCaretaker* temp = new PlantCaretaker();
        nursery1.addStaff(temp);
        nursery1.removeStaff(temp);
        delete temp; // avoid memory leak
    }
    std::cout << "Stress test completed.\n";

    std::cout << "Staff count: " << nursery1.getStaffCount() << "\n";
    std::cout << "Garden count: " << nursery1.getGardenCount() << "\n";

    nursery1.removeStaff(assistant);
    nursery1.removeGarden(garden2);
    delete caretaker;
    delete assistant;
    delete garden1;
    delete garden2;

    std::cout << "Final cleanup done.\n";


    // =========== Strategy Testing ===============
    std::cout << "=== Strategy/Plant Care ===\n";

    std::vector<Plant*> plants;
    plants.push_back(new Lavender());

    std::cout << "\nAssigning care strategies...\n";
    plants[0]->setCareStrategy(new SunnyCare());
    plants[0]->applyCare();

    std::cout << "\nSwitching to ShadyCare...\n";
    plants[0]->setCareStrategy(new ShadyCare());
    plants[0]->applyCare();

    std::cout << "\nSwitching to PartialSunCare...\n";
    plants[0]->setCareStrategy(new PartialSunCare());
    plants[0]->applyCare();

    std::cout << "\n=== Stress Test: Swapping Strategies Dynamically ===\n";
    for (int i = 0; i < 5; ++i) {
        CareStrategy* s;
        if (i % 3 == 0)
            s = new SunnyCare();
        else if (i % 3 == 1)
            s = new ShadyCare();
        else
            s = new PartialSunCare();

        plants[0]->setCareStrategy(s);
        plants[0]->applyCare();
    }

    update_panels();
    doupdate();

    // --- Input Handling ---
    std::string item;
    int ch = getch();
    switch (ch) {
    case KEY_LEFT:
      choice = (choice - 1 + current_menu->size()) % current_menu->size();
      break;
    case KEY_RIGHT:
      choice = (choice + 1) % current_menu->size();
      break;
    case 10: // Enter
      item = current_menu->at(choice);

      if (item == "Back") {
        state = MenuState::MAIN;
        careMenu = false;
        toAdd = nullptr;
        staffToAssign = nullptr;
        choice = 0;
        break;
      } else {
        if (state == MenuState::MAIN) {
          std::string item = main_menu[choice];
          if (item == "Exit")
            running = false;
          else if (item == "Plant Seed") {
            state = MenuState::PLANT;
            choice = 0;
          } else if (item == "Care for Plants") {
            careMenu = true;
            state = MenuState::GARDENS;
            choice = 0;
          } else if (item == "Harvest Plants") {
            harvest = true;
            state = MenuState::GARDENS;
            choice = 0;
          } else if (item == "Save Plants") {
            savePlant = true;
            state = MenuState::GARDENS;
            choice = 0;
          } else if (item == "Hire Staff") {
            state = MenuState::STAFFHIRE;
            choice = 0;
          } else if (item == "Assign Staff") {
            state = MenuState::STAFF;
            choice = 0;
          } else if (item == "View inventory") {
          }
        } else if (state == MenuState::CHOICE) {
          if (item == "Plant in Garden") {
            state = MenuState::GARDENS;
          } else if (item == "Plant in Greenhouse") {
            state = MenuState::GREENHOUSES;
          }
        } else if (state == MenuState::PLANT) {

          toAdd = shopPlants[choice]->clone();
          if (nursery.getBalance() >= toAdd->getPrice()) {
            mvwprintw(info_win, 18, 2, "%s ready to be placed in a %s area",
                      toAdd->getName().c_str(), toAdd->getStrategy().c_str());
            state = MenuState::CHOICE;
            choice = 0;
          } else {
            mvwprintw(info_win, 18, 2,
                      "Insufficient balance to purchase this plant");
            toAdd = nullptr;
            choice = 0;
          }
          wrefresh(info_win);
          std::this_thread::sleep_for(std::chrono::milliseconds(300));

        } else if (state == MenuState::GARDENS) {
          if (toAdd != nullptr) {
            if (nursery.getGardens()[choice]->tryAddItem(toAdd) == true) {
              mvwprintw(info_win, 15, 2, "%s has been planted in %s",
                        toAdd->getName().c_str(), garden_menu[choice].c_str());
              if (toAdd != nursery.removeFromPlantInventory()) {
                nursery.removeFromBalance(toAdd->getPrice());
              }
              toAdd = nullptr;
              state = MenuState::MAIN;
              choice = 0;
            } else {
              mvwprintw(info_win, 15, 2, "The selected garden is full");
              wrefresh(info_win);
              std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
          } else if (staffToAssign != nullptr) {
            PlantCaretaker *caretaker =
                dynamic_cast<PlantCaretaker *>(staffToAssign);
            if (caretaker) {
              nursery.getGardens()[choice]->attach(
                  dynamic_cast<PlantCaretaker *>(staffToAssign));
              mvwprintw(info_win, 15, 2, "%s assigned to %s",
                        staffToAssign->getName().c_str(),
                        garden_menu[choice].c_str());
              staffToAssign = nullptr;
              state = MenuState::MAIN;
              choice = 0;
              wrefresh(info_win);
              std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
          } else if (harvest) {
            Plant *harvested = nursery.getGardens()[choice]->removeMature();
            if (harvested != nullptr) {
              nursery.addToPlantInventory(harvested);
              mvwprintw(info_win, 15, 2,
                        "You have harvested a mature %s to sell",
                        harvested->getName().c_str());
              mvwprintw(info_win, 18, 2, "%s has been added to the salesfloor",
                        harvested->getName().c_str());
            } else {
              mvwprintw(info_win, 15, 2, "No plants ready to harvest");
            }
            wrefresh(info_win);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));

          } else if (savePlant) {
            Plant *harvested = nursery.getGardens()[choice]->removeDying();
            if (harvested != nullptr) {
              nursery.addToPlantInventory(harvested);
              mvwprintw(info_win, 15, 2, "You have saved a dying %s",
                        harvested->getName().c_str());
              mvwprintw(info_win, 18, 2, "%s needs to be planted in %s climate",
                        harvested->getName().c_str(),
                        harvested->getStrategy().c_str());
              toAdd = harvested;
              state = MenuState::GARDENS;
              choice = 0;
            } else {
              mvwprintw(info_win, 15, 2, "No plants ready to harvest");
            }
            wrefresh(info_win);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));

          } else if (careMenu) {

            nursery.getGardens()[choice]->applyCare();
            print_multiline(info_win, 18, 2,
                            "You have successfully tended\n to the plants in "
                            "this garden");
            wrefresh(info_win);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            state = MenuState::MAIN;
          } else {
            // This is a fallback for unhandled menu actions
            mvwprintw(garden_win, 6, 2, "Action for '%s' not implemented.",
                      item.c_str());
            wrefresh(garden_win);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
          }
        } else if (state == MenuState::STAFFHIRE) {
          Staff *staffToHire = toHire[choice];
          if (nursery.getBalance() >= staffToHire->getCost()) {
            nursery.removeFromBalance(staffToHire->getCost());
            nursery.addStaff(staffToHire);

            // Remove from hire pool and update menu
            toHire.erase(toHire.begin() + choice);
            hire_menu.clear();
            for (auto staff : toHire) {
              hire_menu.push_back(staff->getName());
            }
            hire_menu.push_back("Back");

            // Update the assign staff menu as well
            staff_menu.clear();
            for (auto staff : nursery.getStaff()) {
              staff_menu.push_back(staff->getName());
            }
            staff_menu.push_back("Back");

            mvwprintw(info_win, 18, 2, "Successfully hired %s!",
                      staffToHire->getName().c_str());
            state = MenuState::MAIN;
            choice = 0;

            // If it's a customer assistant, they are now on the sales floor
            if (dynamic_cast<CustomerAssistant *>(staffToHire)) {
              // In a full implementation, you would add them to a SalesFloor
              // manager or similar. For now, we can just show a message.
              mvwprintw(info_win, 19, 2, "%s is now on the sales floor!",
                        staffToHire->getName().c_str());
            }

          } else {
            mvwprintw(info_win, 18, 2, "Not enough money to hire %s.",
                      staffToHire->getName().c_str());
          }
          wrefresh(info_win);
          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        } else if (state == MenuState::STAFF) {
          staffToAssign = nursery.getStaff()[choice];
          PlantCaretaker *isCaretaker =
              dynamic_cast<PlantCaretaker *>(staffToAssign);

          if (isCaretaker) {
            state = MenuState::GARDENS;
            choice = 0;
            mvwprintw(info_win, 18, 2, "Select a garden to assign %s to.",
                      staffToAssign->getName().c_str());
          } else {
            mvwprintw(info_win, 18, 2,
                      "I don't know how to take care of gardens!");
            staffToAssign = nullptr; // Reset since they can't be assigned
          }
          wrefresh(info_win);
        }
        break;
      }
    case 27: // ESC key
      if (state != MenuState::MAIN) {
        state = MenuState::MAIN;
        choice = 0;
      }
      break;
    }

    std::cout << "\nTest complete. \n" << std::endl;

    return 0;
}
