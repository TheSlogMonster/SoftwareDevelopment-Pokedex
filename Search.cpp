
#include <algorithm>
#include "Search.h"

using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
void handlePokemonMenu(Pokemon& p) {
    int choice;

    do {
        cout << "\n--- Pokemon Options ---\n";
        cout << "1. View Full Details\n";
        cout << "2. View Stats at Specific Level\n";
        cout << "3. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            p.display();
        }
        else if (choice == 2) {
                p.showStatsAtLevel();
           
        }

    } while (choice != 3);
}
void searchByName(vector<Pokemon>& pokedex, string name) {
    name = toLowerCase(name);

    for (auto &p : pokedex) {
        if (toLowerCase(p.getName()) == name) {
            handlePokemonMenu(p);
            return;
        }
    }

    cout << "Pokemon not found.\n";
}

void searchByID(vector<Pokemon>& pokedex, int id) {
    for (auto &p : pokedex) {
        if (p.getID() == id) {
            handlePokemonMenu(p);
            return;
        }
    }

    cout << "Pokemon not found.\n";
}