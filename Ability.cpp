#include "Ability.h"


Ability::Ability() {
    name = "";
    description = "";
}

Ability::Ability(string name, string description) {
    this->name = name;
    this->description = description;
}


void Ability::display() {
    cout << "- " << name << ": " << description << endl;
}