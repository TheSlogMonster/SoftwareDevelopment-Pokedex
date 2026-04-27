#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Ability.h"
#include "Stats.h"
#include "Location.h"

using namespace std;

class Pokemon {
private:
    string name;
    int id;
    string type1;
    string type2;
    string region;
    string pokedexEntry;

    Stats stats;
    vector<Ability> abilities;
    vector<Location> locations;

public:
    
    Pokemon();
    Pokemon(string name, int id, string type1, string type2,
            string region, string entry, Stats stats);

    void addAbility(const Ability& ability);
    void addLocation(const Location& location);

    void display();
    void showStatsAtLevel();
    void displaySummary() const;
    void displayTypeMatchups();

    void writeSummaryToFile(ofstream& file) const;
    
    string getName() const;
    int getID() const;
};

#endif