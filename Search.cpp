
#include <algorithm>
#include "Search.h"

using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void searchByName(vector<Pokemon>& pokedex, string name) {
    name = toLowerCase(name);

    for (auto &p : pokedex) {
        if (toLowerCase(p.getName()) == name) {
            p.display();
            return;
        }
    }

    cout << "Pokemon not found.\n";
}

void searchByID(vector<Pokemon>& pokedex, int id) {
    for (auto &p : pokedex) {
        if (p.getID() == id) {
            p.display();
            return;
        }
    }

    cout << "Pokemon not found.\n";
}