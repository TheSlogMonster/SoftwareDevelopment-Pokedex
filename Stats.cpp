#include "Stats.h"
#include <iostream>
#include <algorithm>
using namespace std;


//Constructors


Stats::Stats() {
    baseHP = baseAtk = baseDef = baseSpAtk = baseSpDef = baseSpeed = 0;

    ivHP = ivAtk = ivDef = ivSpAtk = ivSpDef = ivSpeed = 0;
    evHP = evAtk = evDef = evSpAtk = evSpDef = evSpeed = 0;

    natAtk = natDef = natSpAtk = natSpDef = natSpeed = 1.0;
    natureName = "Hardy";
}

Stats::Stats(int bhp, int batk, int bdef, int bspatk, int bspdef, int bspeed) {
    baseHP = bhp;
    baseAtk = batk;
    baseDef = bdef;
    baseSpAtk = bspatk;
    baseSpDef = bspdef;
    baseSpeed = bspeed;

    ivHP = ivAtk = ivDef = ivSpAtk = ivSpDef = ivSpeed = 0;
    evHP = evAtk = evDef = evSpAtk = evSpDef = evSpeed = 0;

    natAtk = natDef = natSpAtk = natSpDef = natSpeed = 1.0;
    natureName = "Hardy";
}

//IV / EV setters


void Stats::setIVs(int hp, int atk, int def, int spatk, int spdef, int speed) {
    ivHP = min(31, max(0, hp));
    ivAtk = min(31, max(0, atk));
    ivDef = min(31, max(0, def));
    ivSpAtk = min(31, max(0, spatk));
    ivSpDef = min(31, max(0, spdef));
    ivSpeed = min(31, max(0, speed));
}

void Stats::setEVs(int hp, int atk, int def, int spatk, int spdef, int speed) {
    int total = hp + atk + def + spatk + spdef + speed;

    if (total > 510) {
        cout << "EV limit exceeded (510). All EVs set to 0.\n";
        return;
    }

    auto fixEV = [](int v) {
        if (v < 0) return 0;
        if (v > 252) return 252;
        return (v / 4) * 4; //  multiple of 4
    };

    evHP = fixEV(hp);
    evAtk = fixEV(atk);
    evDef = fixEV(def);
    evSpAtk = fixEV(spatk);
    evSpDef = fixEV(spdef);
    evSpeed = fixEV(speed);
}


 //Nature system (25 natures)


void Stats::setNature(string name) {
    natureName = name;

    // reset all to neutral
    natAtk = natDef = natSpAtk = natSpDef = natSpeed = 1.0;

    // Attack natures 
    if (name == "Lonely")      { natAtk = 1.1; natDef = 0.9; }
    else if (name == "Brave")  { natAtk = 1.1; natSpeed = 0.9; }
    else if (name == "Adamant"){ natAtk = 1.1; natSpAtk = 0.9; }
    else if (name == "Naughty"){ natAtk = 1.1; natSpDef = 0.9; }

    // Defense natures 
    else if (name == "Bold")    { natDef = 1.1; natAtk = 0.9; }
    else if (name == "Relaxed") { natDef = 1.1; natSpeed = 0.9; }
    else if (name == "Impish")  { natDef = 1.1; natSpAtk = 0.9; }
    else if (name == "Lax")     { natDef = 1.1; natSpDef = 0.9; }

    // Speed natures 
    else if (name == "Timid")   { natSpeed = 1.1; natAtk = 0.9; }
    else if (name == "Hasty")   { natSpeed = 1.1; natDef = 0.9; }
    else if (name == "Jolly")   { natSpeed = 1.1; natSpAtk = 0.9; }
    else if (name == "Naive")   { natSpeed = 1.1; natSpDef = 0.9; }

    // Special Attack natures
    else if (name == "Modest")  { natSpAtk = 1.1; natAtk = 0.9; }
    else if (name == "Mild")    { natSpAtk = 1.1; natDef = 0.9; }
    else if (name == "Quiet")   { natSpAtk = 1.1; natSpeed = 0.9; }
    else if (name == "Rash")    { natSpAtk = 1.1; natSpDef = 0.9; }

    //  Special Defense natures 
    else if (name == "Calm")    { natSpDef = 1.1; natAtk = 0.9; }
    else if (name == "Gentle")  { natSpDef = 1.1; natDef = 0.9; }
    else if (name == "Sassy")   { natSpDef = 1.1; natSpeed = 0.9; }
    else if (name == "Careful") { natSpDef = 1.1; natSpAtk = 0.9; }

    // Neutral natures (5) 
    else {
        natAtk = natDef = natSpAtk = natSpDef = natSpeed = 1.0;
    }
}


 //Core formulas


int Stats::calcHP(int base, int iv, int ev, int level) {
    return (((2 * base + iv + (ev / 4)) * level) / 100) + level + 10;
}

int Stats::calcStat(int base, int iv, int ev, float nature, int level) {
    return (int)((((2 * base + iv + (ev / 4)) * level) / 100 + 5) * nature);
}



void Stats::displayBaseStats() {
    cout << "HP Base: " << baseHP << endl;
    cout << "Attack Base: " << baseAtk << endl;
    cout << "Defense Base: " << baseDef << endl;
    cout << "Sp. Attack Base: " << baseSpAtk << endl;
    cout << "Sp. Defense Base: " << baseSpDef << endl;
    cout << "Speed Base: " << baseSpeed << endl;

    cout << "=========================\n";
}

void Stats::displayAtLevel() {
    int level;

    cout << "\nEnter level (1-100): ";
    cin >> level;

    if (level < 1 || level > 100) {
        cout << "Invalid level.\n";
        return;
    }

    
    int ivH, ivA, ivD, ivSA, ivSD, ivS;

    cout << "\nEnter IVs (0-31 each stat)\n";

    auto inputIV = [](string name) {
        int val;

        while (true) {
            cout << name << " IV: ";
            cin >> val;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter a number.\n";
                continue;
            }

            if (val < 0 || val > 31) {
                cout << "IV must be between 0 and 31.\n";
                continue;
            }

            return val;
        }
    };

    ivH = inputIV("HP");
    ivA = inputIV("Attack");
    ivD = inputIV("Defense");
    ivSA = inputIV("Sp. Attack");
    ivSD = inputIV("Sp. Defense");
    ivS = inputIV("Speed");

    setIVs(ivH, ivA, ivD, ivSA, ivSD, ivS);

 
    int evH, evA, evD, evSA, evSD, evS;
    int totalEV = 0;

    cout << "\nEnter EVs (0-252 each, multiples of 4, total max 510)\n";

    auto inputEV = [&](string name) {
        int val;

        while (true) {
            cout << name << " EV: ";
            cin >> val;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter a number.\n";
                continue;
            }

            if (val < 0 || val > 252) {
                cout << "EV must be between 0 and 252.\n";
                continue;
            }

            if (val % 4 != 0) {
                cout << "EV must be a multiple of 4 (or 0).\n";
                continue;
            }

            return val;
        }
    };

    evH = inputEV("HP"); totalEV += evH;
    evA = inputEV("Attack"); totalEV += evA;
    evD = inputEV("Defense"); totalEV += evD;
    evSA = inputEV("Sp. Attack"); totalEV += evSA;
    evSD = inputEV("Sp. Defense"); totalEV += evSD;
    evS = inputEV("Speed"); totalEV += evS;

    if (totalEV > 510) {
        cout << "\nTotal EVs exceed 510. Resetting all EVs to 0.\n";
        setEVs(0, 0, 0, 0, 0, 0);
    } else {
        setEVs(evH, evA, evD, evSA, evSD, evS);
    }

  
    string natureInput;
    cout << "\nEnter Nature: ";
    cin >> natureInput;

    string validNatures[] = {
        "Lonely","Brave","Adamant","Naughty",
        "Bold","Relaxed","Impish","Lax",
        "Timid","Hasty","Jolly","Naive",
        "Modest","Mild","Quiet","Rash",
        "Calm","Gentle","Sassy","Careful"
    };

    bool found = false;

    for (int i = 0; i < 20; i++) {
        if (natureInput == validNatures[i]) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Neutral nature assumed.\n";
        natureInput = "Neutral";
    }

    setNature(natureInput);
    // OUTPUT
    cout << "\n=========================\n";
    cout << "FINAL STATS AT LEVEL " << level << endl;
    cout << "=========================\n";

    cout << "HP: " << calcHP(baseHP, ivH, evH, level) << endl;

    cout << "Attack: " << calcStat(baseAtk, ivA, evA, natAtk, level) << endl;
    cout << "Defense: " << calcStat(baseDef, ivD, evD, natDef, level) << endl;
    cout << "Sp. Attack: " << calcStat(baseSpAtk, ivSA, evSA, natSpAtk, level) << endl;
    cout << "Sp. Defense: " << calcStat(baseSpDef, ivSD, evSD, natSpDef, level) << endl;
    cout << "Speed: " << calcStat(baseSpeed, ivS, evS, natSpeed, level) << endl;

    cout << "=========================\n";
}