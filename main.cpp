#include "Card.h"
#include "CareStrategy.h"
#include "Caretaker.h"
#include "Cash.h"
#include "CustomerAssistant.h"
#include "CustomerAssistantCreator.h"
#include "EFT.h"
#include "FussyCust.h"
#include "Garden.h"
#include "GardenIterator.h"
#include "GreenhouseController.h"
#include "GreenhouseIterator.h"
#include "Inventory.h"
#include "Iterator.h"
#include "Lavender.h"
#include "LavenderCreator.h"
#include "Lily.h"
#include "LilyCreator.h"
#include "Nursery.h"
#include "PartialSun.h"
#include "PartialSunCare.h"
#include "PaymentStrategy.h"
#include "Plant.h"
#include "PlantCaretaker.h"
#include "PlantCaretakerCreator.h"
#include "PlantIterator.h"
#include "PlantMemento.h"
#include "Rose.h"
#include "RoseCreator.h"
#include "Shady.h"
#include "ShadyCare.h"
#include "Sunny.h"
#include "SunnyCare.h"
#include "Transaction.h"
#include "Tulip.h"
#include "TulipCreator.h"
#include "greenHouse.h"
#include <iostream>
#include <random>
#include <vector>

#include <chrono>
#include <iomanip>
#include <ncurses.h>
#include <panel.h>
#include <regex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

void print_with_ansi(WINDOW *win, int y, int x, const std::string text) {
  int cx = x;
  std::regex color_regex("\033\\[38;5;([0-9]+)m");
  std::smatch match;
  std::string remaining = text;

  while (std::regex_search(remaining, match, color_regex)) {
    // Print text before the escape, handling newlines
    std::string before = match.prefix();
    for (char c : before) {
      if (c == '\n') {
        y++;
        cx = x;
        wmove(win, y, cx);
      } else {
        mvwaddch(win, y, cx++, c);
      }
    }

    // Parse and apply color
    int color_id = std::stoi(match[1]);
    if (color_id >= 0 && color_id < 256) {
      init_pair(color_id, color_id, -1);
      wattron(win, COLOR_PAIR(color_id));
    }

    remaining = match.suffix();
  }

  // Print remaining text (after last color code)
  for (char c : remaining) {
    if (c == '\n') {
      y++;
      cx = x;
      wmove(win, y, cx);
    } else {
      mvwaddch(win, y, cx++, c);
    }
  }

  wattroff(win, A_COLOR);
}

void print_multiline(WINDOW *win, int start_y, int start_x,
                     const std::string &text) {
  std::stringstream ss(text);
  std::string line;
  int y = start_y;

  while (std::getline(ss, line, '\n')) {
    print_with_ansi(win, y, start_x, line);
    y++;
  }
}

enum class MenuState { MAIN, PLANT, WATER, HARVEST, GARDENS, STAFFHIRE, STAFF };

WINDOW *create_newwin(int height, int width, int starty, int startx,
                      const char *title) {
  WINDOW *local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0);
  mvwprintw(local_win, 0, 2, " %s ", title);
  wrefresh(local_win);
  return local_win;
}

std::string format_time(int hour, int minute) {
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2)
      << std::setfill('0') << minute;
  return oss.str();
}

std::string get_time_phase(int hour) {
  if (hour >= 6 && hour < 12)
    return "Morning";
  if (hour >= 12 && hour < 18)
    return "Afternoon";
  if (hour >= 18 && hour < 22)
    return "Evening";
  return "Night";
}

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
  std::vector<std::string> garden_menu = {"G 1 (Sunny)",
                                          "G 2 (Sunny)",
                                          "G 3 (Partial sun)",
                                          "G 4 (Partial sun)",
                                          "G 5 (Shady)",
                                          "G 6 (Shady)",
                                          "Back"};
  staff_menu.push_back("Back");
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
  int prevHour = 0;
  // random events happening using mersenne twister
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> chance(0.0, 1.0);
  nursery.addToBalance(500);
  bool careMenu = false;

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
          garden->applyRays();
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
      current_menu = &water_menu;
      break;
    case MenuState::HARVEST:
      current_menu = &harvest_menu;
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
    }

    // --- Info Panel ---
    werase(info_win);
    box(info_win, 0, 0);
    wattron(info_win, COLOR_PAIR(3));
    mvwprintw(info_win, 0, 2, " Nursery Info ");
    wattroff(info_win, COLOR_PAIR(3));
    mvwprintw(info_win, 2, 2, "Day: %d", day);
    mvwprintw(info_win, 3, 2, "Time: %s", time_str.c_str());
    mvwprintw(info_win, 4, 2, "Phase: %s", phase.c_str());
    mvwprintw(info_win, 6, 2, "Balance: R%.2f", nursery.getBalance());
    mvwprintw(info_win, 7, 2, "Temp: 22°C");

    // --- Show hover description ---
    std::string hovered = (*current_menu)[choice];
    if (descriptions.count(hovered)) {
      wattron(info_win, COLOR_PAIR(4));
      mvwprintw(info_win, 9, 2, "%s:", hovered.c_str());
      wattroff(info_win, COLOR_PAIR(4));

      int line = 10;
      std::istringstream desc_stream(descriptions[hovered]);
      std::string line_text;
      while (std::getline(desc_stream, line_text)) {
        mvwprintw(info_win, line++, 2, "%s", line_text.c_str());
      }
    }

    // --- Menu Panel ---
    werase(menu_win);
    box(menu_win, 0, 0);
    wattron(menu_win, COLOR_PAIR(2));
    mvwprintw(menu_win, 0, 2, " Menu ");
    wattroff(menu_win, COLOR_PAIR(2));

    for (size_t i = 0; i < current_menu->size(); i++) {
      if ((int)i == choice)
        wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, 2, 2 + i * 18, "%s", (*current_menu)[i].c_str());
      if ((int)i == choice)
        wattroff(menu_win, A_REVERSE);
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
            state = MenuState::WATER;
            choice = 0;
          } else if (item == "Harvest Plants") {
            state = MenuState::HARVEST;
            choice = 0;
          } else if (item == "Hire Staff") {
            state = MenuState::STAFFHIRE;
            choice = 0;
          } else if (item == "Assign Staff") {
            state = MenuState::STAFF;
            choice = 0;
          } else if (item == "View inventory") {
          }
        } else if (state == MenuState::PLANT) {

          toAdd = shopPlants[choice]->clone();
          if (nursery.getBalance() >= toAdd->getPrice()) {
            mvwprintw(info_win, 18, 2, "%s ready to be placed in a %s area",
                      toAdd->getName().c_str(), toAdd->getStrategy().c_str());
            state = MenuState::GARDENS;
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
              nursery.removeFromBalance(toAdd->getPrice());
              toAdd = nullptr;
              state = MenuState::MAIN;
              choice = 0;
            } else {
              mvwprintw(info_win, 15, 2, "The selected garden is full");
              wrefresh(info_win);
              std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
          } else if (careMenu == true) {
            nursery.getGardens()[choice]->applyCare();
          }

        } else {
          std::string item = (*current_menu)[choice];
          if (item == "Back") {
            state = MenuState::MAIN;
            choice = 0;
          } else {
            mvwprintw(garden_win, 6, 2, "Action: %s...", item.c_str());
            wrefresh(garden_win);
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
          }
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

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  endwin();
  return 0;
}
