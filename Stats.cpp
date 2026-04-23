#include "Stats.h"
#include <cmath>

// With parameters
Stats::Stats(int hp, int atk, int def, int spAtk, int spDef, int spd) {
    baseHP = hp;
    baseAttack = atk;
    baseDefense = def;
    baseSpAttack = spAtk;
    baseSpDefense = spDef;
    baseSpeed = spd;
}

// Default
Stats::Stats() {
    baseHP = baseAttack = baseDefense = 0;
    baseSpAttack = baseSpDefense = baseSpeed = 0;
}

// HP formula
int Stats::calculateHP(int base, int level) {
    int IV = 0;
    int EV = 0;

    return floor((((2 * base + IV + (EV / 4.0)) * level) / 100.0) + level + 10);
}

// Other stats formula
int Stats::calculateOther(int base, int level) {
    int IV = 0;
    int EV = 0;
    float nature = 1.0;

    return floor(((((2 * base + IV + (EV / 4.0)) * level) / 100.0) + 5) * nature);
}


void Stats::display() {
    cout << "\n--- Level 50 (Base Stats at 0 EVs and IVs) ---\n";
    cout << "HP: " << calculateHP(baseHP, 50) << endl;
    cout << "Attack: " << calculateOther(baseAttack, 50) << endl;
    cout << "Defense: " << calculateOther(baseDefense, 50) << endl;
    cout << "Sp. Attack: " << calculateOther(baseSpAttack, 50) << endl;
    cout << "Sp. Defense: " << calculateOther(baseSpDefense, 50) << endl;
    cout << "Speed: " << calculateOther(baseSpeed, 50) << endl;

    cout << "\n--- Full Range (0 - 100 at 0 EVs and IVs) ---\n";

    cout << "HP: "
         << calculateHP(baseHP, 1) << " - "
         << calculateHP(baseHP, 100) << endl;

    cout << "Attack: "
         << calculateOther(baseAttack, 1) << " - "
         << calculateOther(baseAttack, 100) << endl;

    cout << "Defense: "
         << calculateOther(baseDefense, 1) << " - "
         << calculateOther(baseDefense, 100) << endl;

    cout << "Sp. Attack: "
         << calculateOther(baseSpAttack, 1) << " - "
         << calculateOther(baseSpAttack, 100) << endl;

    cout << "Sp. Defense: "
         << calculateOther(baseSpDefense, 1) << " - "
         << calculateOther(baseSpDefense, 100) << endl;

    cout << "Speed: "
         << calculateOther(baseSpeed, 1) << " - "
         << calculateOther(baseSpeed, 100) << endl;
}