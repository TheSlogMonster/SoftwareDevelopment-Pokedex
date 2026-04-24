#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <string>
using namespace std;

class Stats {
private:
    // Base stats
    int baseHP, baseAtk, baseDef, baseSpAtk, baseSpDef, baseSpeed;

    // IVs
    int ivHP, ivAtk, ivDef, ivSpAtk, ivSpDef, ivSpeed;

    // EVs
    int evHP, evAtk, evDef, evSpAtk, evSpDef, evSpeed;

    // Nature multipliers
    float natAtk, natDef, natSpAtk, natSpDef, natSpeed;

    string natureName;

    int calcHP(int base, int iv, int ev, int level);
    int calcStat(int base, int iv, int ev, float nature, int level);

public:
    Stats();

    Stats(int bhp, int batk, int bdef, int bspatk, int bspdef, int bspeed);

    // setters
    void setIVs(int hp, int atk, int def, int spatk, int spdef, int speed);
    void setEVs(int hp, int atk, int def, int spatk, int spdef, int speed);
    void setNature(string name);

    void displayAtLevel();
    void displayBaseStats();
};

#endif