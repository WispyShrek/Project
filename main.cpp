#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Garden.h"
#include "GardenIterator.h"
#include "Iterator.h"

#include "Plant.h"
#include "PlantCreator.h"
#include "RoseCreator.h"
#include "TulipCreator.h"
#include "LavenderCreator.h"
#include "LilyCreator.h"

// Add concrete plant headers for dynamic_cast
#include "Rose.h"
#include "Tulip.h"
#include "Lavender.h"
#include "Lily.h"

// Add concrete garden headers
#include "Sunny.h"
#include "PartialSun.h"
#include "Shady.h"

// Add care strategy headers
#include "CareStrategy.h"
#include "SunnyCare.h"
#include "PartialSunCare.h"
#include "ShadyCare.h"

// Staff and creators
#include "Staff.h"
#include "PlantCaretaker.h"
#include "CustomerAssistant.h"
#include "PlantCaretakerCreator.h"
#include "CustomerAssistantCreator.h"

struct UserGarden {
    std::string name;
    std::string type; // "Sunny", "Partial Sun", "Shady"
    Garden* garden;
};

struct StaffRecord {
    Staff* ptr;
    std::string name;
    std::string role;
};

static void clearLine() {
    if (!std::cin.good()) std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void pressEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static const char* plantTypeName(Plant* p) {
    if (dynamic_cast<Rose*>(p)) return "Rose";
    if (dynamic_cast<Tulip*>(p)) return "Tulip";
    if (dynamic_cast<Lavender*>(p)) return "Lavender";
    if (dynamic_cast<Lily*>(p)) return "Lily";
    return "Plant";
}

static std::string getPlantStateName(Plant* p) {
    if(!p){
        return "Unknown";
    }else{
        return p->getState(); 
    }
}

//garden iterator to be implemented....
static void listGardens(const std::vector<UserGarden>& gs) {
    if (gs.empty()) {
        std::cout << "No gardens yet.\n";
        return;
    }
    for (size_t i = 0; i < gs.size(); ++i) {
        std::cout << " [" << i << "] " << gs[i].name << " (" << gs[i].type << ")\n";
    }
}

//uses garden iterator to iterate over plants in garden.
static void viewGardenPlants(Garden* g) {
    Iterator<Plant*>* it = g->CreateIterator();
    if (!it) { std::cout << "(no plants)\n"; return; }
    
    int idx = 0;
    bool hasPlants = false;
    it->first();
    while (!it->isDone()) {
        Plant* p = it->currItem();
        if (p) {
            hasPlants = true;
            std::cout << "  [" << idx << "] " << plantTypeName(p) 
                      << " - State: " << getPlantStateName(p) << "\n";
        }
        ++idx;
        it->next();
    }
    
    if (!hasPlants) {
        std::cout << "(no plants)\n";
    }
}

static Garden* createGardenFromMenu(std::string& outType) {
    std::cout << "\nChoose garden type:\n";
    std::cout << "  1) Sunny Garden\n";
    std::cout << "  2) Partial Sun Garden\n";
    std::cout << "  3) Shady Garden\n";
    std::cout << "Enter choice: ";
    
    int choice = -1;
    if (!(std::cin >> choice)) { 
        clearLine(); 
        return nullptr; 
    }
    clearLine();

    switch (choice) {
        case 1: 
            outType = "Sunny";
            return new Sunny();
        case 2: 
            outType = "Partial Sun";
            return new PartialSun();
        case 3: 
            outType = "Shady";
            return new Shady();
        default: 
            return nullptr;
    }
}

static Plant* createPlantFromMenu() {
    std::cout << "\nChoose plant type:\n";
    std::cout << "  1) Rose\n";
    std::cout << "  2) Tulip\n";
    std::cout << "  3) Lavender\n";
    std::cout << "  4) Lily\n";
    std::cout << "Enter choice: ";
    
    int choice = -1;
    if (!(std::cin >> choice)) { 
        clearLine(); 
        return nullptr; 
    }
    clearLine();

    //uses the factory method for plants to create plants
    switch (choice) {
        case 1: { RoseCreator c; return c.createPlant(); }
        case 2: { TulipCreator c; return c.createPlant(); }
        case 3: { LavenderCreator c; return c.createPlant(); }
        case 4: { LilyCreator c; return c.createPlant(); }
        default: return nullptr;
    }
}

static CareStrategy* selectCareStrategy() {
    std::cout << "\nChoose care strategy to apply:\n";
    std::cout << "  1) Sunny Care\n";
    std::cout << "  2) Partial Sun Care\n";
    std::cout << "  3) Shady Care\n";
    std::cout << "Enter choice: ";
    
    int choice = -1;
    if (!(std::cin >> choice)) { 
        clearLine(); 
        return nullptr; 
    }
    clearLine();

    switch (choice) {
        case 1: return new SunnyCare();
        case 2: return new PartialSunCare();
        case 3: return new ShadyCare();
        default: return nullptr;
    }
}

static void applyCareToGarden(UserGarden& ug) {
    std::cout << "\nApplying care...." << " to " << ug.name << " (" << ug.type << ")...\n";
    
    // Apply care to all plants in the garden
    Iterator<Plant*>* it = ug.garden->CreateIterator();
    if (!it) { 
        return; 
    }
    
    ug.garden->applyCare();
    std::cout << "Care applied to all plants in the garden.\n";
}

int main() {
    std::vector<UserGarden> gardens;
    int actionsRemaining = 50;
    double balance = 500.0;
    int day = 1;
    bool running = true;

    //for now.... we should add staff list to the singleton later
    std::vector<StaffRecord> staffList;

    while (running && actionsRemaining > 0) {
        std::cout << "Day: " << day << "\n";
        std::cout << "Actions Remaining: " << actionsRemaining << " | Balance: " << balance << "\n";
        std::cout << "================================================\n";
        std::cout << "1) Create a new garden\n";
        std::cout << "2) Add a plant to a garden\n";
        std::cout << "3) View gardens and plants\n";
        std::cout << "4) Apply care strategy to a garden\n";
        std::cout << "5) Hire staff\n";
        std::cout << "6) View staff\n"; 
        std::cout << "0) Exit\n";
        std::cout << "Choose: ";

        int choice = -1;
        if (!(std::cin >> choice)) { 
            clearLine(); 
            continue; 
        }
        clearLine();

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::cout << "\nEnter garden name: ";
                std::string name;
                std::getline(std::cin, name);
                if (name.empty()) {
                    name = "Garden " + std::to_string(gardens.size() + 1);
                }
                
                std::string gardenType;
                Garden* g = createGardenFromMenu(gardenType);
                
                if (!g) {
                    std::cout << "Invalid garden type selection.\n";
                    pressEnter();
                    break;
                }
                
                gardens.push_back(UserGarden{ name, gardenType, g });
                std::cout << "\nCreated " << gardenType << " garden: " << name << "\n";
                actionsRemaining--;
                pressEnter();
                break;
            }
            case 2: {
                if (gardens.empty()) {
                    std::cout << "\nCreate a garden first.\n";
                    pressEnter();
                    break;
                }
                
                std::cout << "\nSelect a garden:\n";
                listGardens(gardens);
                std::cout << "Enter garden index: ";
                
                int gix = -1;
                if (!(std::cin >> gix)) { 
                    clearLine(); 
                    break; 
                }
                clearLine();
                
                if (gix < 0 || gix >= (int)gardens.size()) {
                    std::cout << "Invalid garden index.\n";
                    pressEnter();
                    break;
                }

                Plant* p = createPlantFromMenu();
                if (!p) {
                    std::cout << "Invalid plant choice.\n";
                    pressEnter();
                    break;
                }

                gardens[gix].garden->addItem(p);
                std::cout << "\nAdded " << plantTypeName(p) 
                          << " to " << gardens[gix].name 
                          << " (initial state: " << getPlantStateName(p) << ")\n";
                actionsRemaining--;
                pressEnter();
                break;
            }
            case 3: {
                if (gardens.empty()) {
                    std::cout << "\nNo gardens to show.\n";
                    pressEnter();
                    break;
                }
                
                std::cout << "\n";
                for (auto& g : gardens) {
                    std::cout << g.name << " (" << g.type << "):\n";
                    viewGardenPlants(g.garden);
                    std::cout << "\n";
                }
                pressEnter();
                break;
            }
            case 4: {
                if (gardens.empty()) {
                    std::cout << "\nCreate a garden first.\n";
                    pressEnter();
                    break;
                }
                
                std::cout << "\nSelect a garden to care for:\n";
                listGardens(gardens);
                std::cout << "Enter garden index: ";
                
                int gix = -1;
                if (!(std::cin >> gix)) { 
                    clearLine(); 
                    break; 
                }
                clearLine();
                
                if (gix < 0 || gix >= (int)gardens.size()) {
                    std::cout << "Invalid garden index.\n";
                    pressEnter();
                    break;
                }
                
                applyCareToGarden(gardens[gix]);
                actionsRemaining--;
                pressEnter();
                break;
            }
            case 5: { 
                std::cout << "\nHire which staff?\n";
                std::cout << "  1) Plant Caretaker (100 credits)\n";
                std::cout << "  2) Customer Assistant (150 credits)\n";
                std::cout << "Enter choice: ";

                int sc = -1;
                if (!(std::cin >> sc)) { clearLine(); break; }
                clearLine();

                Staff* sPtr = nullptr;
                std::string role;
                if (sc == 1) {
                    PlantCaretakerCreator creator;
                    sPtr = creator.createStaff();
                    role = "Plant Caretaker";
                    balance -= 100.0;
                } else if (sc == 2) {
                    CustomerAssistantCreator creator;
                    sPtr = creator.createStaff();
                    role = "Customer Assistant";
                    balance -= 150.0;
                } else {
                    std::cout << "Invalid staff type.\n";
                    pressEnter();
                    break;
                }

                if (!sPtr) {
                    std::cout << "Failed to create staff.\n";
                    pressEnter();
                    break;
                }

                // Ask for a display name (since Staff has no name field)
                std::cout << "Enter staff name: ";
                std::string name;
                std::getline(std::cin, name);
                if (name.empty()) {
                    int countRole = 0;
                    for (const auto& rec : staffList) {
                        if (rec.role == role) ++countRole;
                    }
                    name = role + std::string(" ") + std::to_string(countRole + 1);
                }

                staffList.push_back(StaffRecord{ sPtr, name, role });
                std::cout << "Hired " << role << " - " << name 
                          << ". Total staff: " << staffList.size() << "\n";
                actionsRemaining--; // count hiring as an action
                pressEnter();
                break;
            }
            case 6: {
                if (staffList.empty()) {
                    std::cout << "\nNo staff hired yet.\n";
                } else {
                    std::cout << "\nHired Staff:\n";
                    for (size_t i = 0; i < staffList.size(); ++i) {
                        std::cout << " [" << i << "] " << staffList[i].name << " (" << staffList[i].role << ")\n";
                    }
                }
                pressEnter();
                break;
            }
            default:
                std::cout << "Invalid option.\n";
                pressEnter();
                break;
        }
    }

    if (actionsRemaining == 0) {
        std::cout << "\nYou've run out of actions for today!\n";
    }
    
    std::cout << "\nExiting. Goodbye!\n";
    return 0;
}