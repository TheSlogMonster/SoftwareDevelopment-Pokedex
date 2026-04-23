#ifndef STATS_H
#define STATS_H

#include <iostream>
using namespace std;

class Stats {
private:
    int baseHP;
    int baseAttack;
    int baseDefense;
    int baseSpAttack;
    int baseSpDefense;
    int baseSpeed;

    int calculateHP(int base, int level);
    int calculateOther(int base, int level);

public:
    Stats(int hp, int atk, int def, int spAtk, int spDef, int spd);
    Stats();

    void display();
};

#endif