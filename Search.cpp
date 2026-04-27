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
        cout << "1. View Basic Details\n";
        cout << "2. View Stats at Specific Level\n";
        cout << "3. View Type Matchups\n";
        cout << "4. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            p.display();
        }
        else if (choice == 2) {
                p.showStatsAtLevel();
           
        }
        else if (choice == 3) {
                p.displayTypeMatchups();
}

    } while (choice != 4);
}
void searchByName(vector<Pokemon>& pokedex, string name) {
    name = toLowerCase(name);

    auto it = find_if(pokedex.begin(), pokedex.end(),
        [name](const Pokemon& p) {
            return toLowerCase(p.getName()) == name;
        });

    if (it != pokedex.end()) {
        handlePokemonMenu(*it);
    } else {
        cout << "Pokemon not found.\n";
    }
}

void searchByID(vector<Pokemon>& pokedex, int id) {

    auto it = find_if(pokedex.begin(), pokedex.end(),
        [id](const Pokemon& p) {
            return p.getID() == id;
        });

    if (it != pokedex.end()) {
        handlePokemonMenu(*it);
    } else {
        cout << "Pokemon not found.\n";
    }
}

void savePokedexToFile(const vector<Pokemon>& pokedex) {
    ofstream file("pokedex.txt");

    if (!file) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }

    file << "SAVED POKEDEX:\n";

    vector<Pokemon> sortedList = pokedex;

    sort(sortedList.begin(), sortedList.end(),
        [](const Pokemon& a, const Pokemon& b) {
            return a.getID() < b.getID();
        });

    for (const auto& p : sortedList) {
        p.writeSummaryToFile(file);
    }

    file << "\n";

    file.close();

    cout << "Pokedex saved to pokedex.txt successfully.\n";
}