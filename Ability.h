#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <iostream>
using namespace std;

class Ability {
private:
    string name;
    string description;

public:
    Ability();
    Ability(string name, string description);

    void display();
};

#endif