#include <iostream>
#include <vector>
#include <algorithm>
#include "Pokemon.h"
#include "Search.h"
using namespace std;


int main() {
    vector<Pokemon> pokedex;

    //Pikachu 
    Stats pikaStats(35,55,40,50,50,90);

    pikaStats.setIVs(0,0,0,0,0,0);
    pikaStats.setEVs(0,0,0,0,0,0);
    pikaStats.setNature("Serious");

    Pokemon pikachu("Pikachu",25,"Electric","","Kanto","A friendly electric mouse.",pikaStats);

    pikachu.addAbility(Ability("Static", "May paralyze on contact."));
    pikachu.addLocation(Location("Viridian Forest"));

    pokedex.push_back(pikachu);

    //Bulbasaur 
    Stats bulbaStats(45,49,49,65,65,45);

    bulbaStats.setIVs(0,0,0,0,0,0);
    bulbaStats.setEVs(0,0,0,0,0,0);
    bulbaStats.setNature("Serious");

    Pokemon bulbasaur("Bulbasaur",1,"Grass","Poison","Kanto",
        "It carries a seed on its back right from birth. As its body grows larger, the seed does too.",
        bulbaStats);

    bulbasaur.addAbility(Ability("Overgrow", "Powers up Grass-type moves when the Pokémon's HP is low."));
    bulbasaur.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(bulbasaur);

    //Ivysaur
    Stats ivyStats(60,62,63,80,80,60);

    ivyStats.setIVs(0,0,0,0,0,0);
    ivyStats.setEVs(0,0,0,0,0,0);
    ivyStats.setNature("Serious");

    Pokemon ivysaur("Ivysaur",2,"Grass","Poison","Kanto",
        "The bulb on its back grows as it absorbs nutrients. The bulb gives off a pleasant aroma when it blooms.",
        bulbaStats);

    ivysaur.addAbility(Ability("Overgrow", "Powers up Grass-type moves when the Pokémon's HP is low."));
    ivysaur.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(ivysaur);

    //Venusaur
    Stats venuStats(80,82,83,100,100,80);

    venuStats.setIVs(0,0,0,0,0,0);
    venuStats.setEVs(0,0,0,0,0,0);
    venuStats.setNature("Serious");

    Pokemon venosaur("Venusaur",3,"Grass","Poison","Kanto",
        "It carries a seed on its back right from birth. As its body grows larger, the seed does too.",
        bulbaStats);

    venosaur.addAbility(Ability("Overgrow", "Powers up Grass-type moves when the Pokémon's HP is low."));
    venosaur.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(venosaur);

    //Menu
    int choice;

    do {
        cout << "\n===== Pokedex System =====\n";
        cout << "1. Search by Pokemon Name\n";
        cout << "2. Search by Pokemon ID\n";
        cout << "3. View All Pokemon\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter Pokemon name: ";
            cin >> name;
            searchByName(pokedex, name);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter Pokemon ID: ";
            cin >> id;
            searchByID(pokedex, id);
        }
        else if (choice == 3) {
        listAllPokemon(pokedex);
        }

    } while (choice != 4);

    return 0;
}