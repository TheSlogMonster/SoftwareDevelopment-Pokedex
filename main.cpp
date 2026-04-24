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

    //Menu
    int choice;

    do {
        cout << "\n===== Pokemon Search System =====\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by ID\n";
        cout << "3. Exit\n";
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

    } while (choice != 3);

    return 0;
}