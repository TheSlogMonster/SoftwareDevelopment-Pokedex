#include "Pokemon.h"
#include "TypeChart.h"
#include <iostream>

//Default 
Pokemon::Pokemon() {
    name = "";
    id = 0;
    type1 = "";
    type2 = "";
    region = "";
    pokedexEntry = "";
}

//With parameters
Pokemon::Pokemon(string name, int id, string type1, string type2,
                 string region, string entry, Stats stats) {
    this->name = name;
    this->id = id;
    this->type1 = type1;
    this->type2 = type2;
    this->region = region;
    this->pokedexEntry = entry;
    this->stats = stats;
}

// Ability
void Pokemon::addAbility(const Ability& ability) {
    abilities.push_back(ability);
}

// Location
void Pokemon::addLocation(const Location& location) {
    locations.push_back(location);
}


string Pokemon::getName() const {
    return name;
}

int Pokemon::getID() const {
    return id;
}


void Pokemon::display() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Type: " << type1;
    if (type2 != "") cout << "/" << type2;
    cout << endl;

    cout << "Region: " << region << endl;
    cout << "Pokedex: " << pokedexEntry << endl;

    cout << "\n=========================\n";
    cout << "BASE STATS\n";
    stats.displayBaseStats();
    cout << "\nAbilities:\n";
    for (auto &a : abilities)
        a.display();

    cout << "\nLocations:\n";
    for (auto &l : locations)
        l.display();
}
void Pokemon::showStatsAtLevel() {
    stats.displayAtLevel();
}
void Pokemon::displaySummary() const {
    cout << "ID: " << id << " | Name: " << name << " | Type: " << type1;

    if (type2 != "") {
        cout << "/" << type2;
    }

    cout << endl;
}
void listAllPokemon(const vector<Pokemon>& pokedex) {
    cout << "\n===== POKEDEX LIST =====\n";

    // Create a copy so original order is preserved
    vector<Pokemon> sortedList = pokedex;

    // Sort by ID
    sort(sortedList.begin(), sortedList.end(),
        [](const Pokemon& a, const Pokemon& b) {
            return a.getID() < b.getID();
        });

    // Display sorted list
    for (const auto &p : sortedList) {
        p.displaySummary();
    }

    cout << "=========================\n";
}

void Pokemon::writeSummaryToFile(ofstream& file) const {
    file << "ID: " << id << " | Name: " << name << " | Type: " << type1;

    if (type2 != "") {
        file << "/" << type2;
    }

    file << endl;
}

void Pokemon::displayTypeMatchups() {
    string allTypes[] = {
        "Normal","Fire","Water","Electric","Grass","Ice",
        "Fighting","Poison","Ground","Flying","Psychic",
        "Bug","Rock","Ghost","Dragon","Dark","Steel","Fairy"
    };

    cout << "\n=== TYPE MATCHUPS ===\n";

    for (int i = 0; i < 18; i++) {
        float mult = getEffectiveness(allTypes[i], type1);

        if (type2 != "")
            mult *= getEffectiveness(allTypes[i], type2);

        if (mult == 2.0) {
            cout << allTypes[i] << "  Weak (2x)\n";
        }
        else if (mult == 4.0) {
            cout << allTypes[i] << "  VERY Weak (4x)\n";
        }
        else if (mult == 0.5) {
            cout << allTypes[i] << "  Resistant (0.5x)\n";
        }
        else if (mult == 0.25) {
            cout << allTypes[i] << "  VERY Resistant (0.25x)\n";
        }
        else if (mult == 0.0) {
            cout << allTypes[i] << "  Immune (0x)\n";
        }
    }

    cout << "=====================\n";
}