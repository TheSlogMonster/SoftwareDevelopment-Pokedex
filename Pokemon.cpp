#include "Pokemon.h"
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