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

    //Bulbasaur 
    Stats bulbaStats(45,49,49,65,65,45);

    bulbaStats.setIVs(0,0,0,0,0,0);
    bulbaStats.setEVs(0,0,0,0,0,0);
    bulbaStats.setNature("Serious");

    Pokemon bulbasaur("Bulbasaur",1,"Grass","Poison","Kanto",
        "It carries a seed on its back right from birth. As its body grows larger, the seed does too.",
        bulbaStats);

    bulbasaur.addAbility(Ability("Overgrow", "Powers up Grass-type moves when the Pokemon's HP is low."));
    bulbasaur.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(bulbasaur);

    //Ivysaur
    Stats ivyStats(60,62,63,80,80,60);

    ivyStats.setIVs(0,0,0,0,0,0);
    ivyStats.setEVs(0,0,0,0,0,0);
    ivyStats.setNature("Serious");

    Pokemon ivysaur("Ivysaur",2,"Grass","Poison","Kanto",
        "The bulb on its back grows as it absorbs nutrients. The bulb gives off a pleasant aroma when it blooms.",
        ivyStats);

    ivysaur.addAbility(Ability("Overgrow", "Powers up Grass-type moves when the Pokemon's HP is low."));
    ivysaur.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(ivysaur);

    //Venusaur
    Stats venuStats(80,82,83,100,100,80);

    venuStats.setIVs(0,0,0,0,0,0);
    venuStats.setEVs(0,0,0,0,0,0);
    venuStats.setNature("Serious");

    Pokemon venosaur("Venusaur",3,"Grass","Poison","Kanto",
        "It carries a seed on its back right from birth. As its body grows larger, the seed does too.",
        venuStats);

    venosaur.addAbility(Ability("Overgrow", "Powers up Grass-type moves when the Pokemon's HP is low."));
    venosaur.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(venosaur);

    //Charmander
    Stats charmanStats(39,52,43,60,50,65);

    charmanStats.setIVs(0,0,0,0,0,0);
    charmanStats.setEVs(0,0,0,0,0,0);
    charmanStats.setNature("Serious");

    Pokemon charmander("Charmander",4,"Fire","","Kanto",
        "If it's healthy, the flame on the tip of its tail will burn vigrously, even if it gets a bit wet.",
        charmanStats);

    charmander.addAbility(Ability("Blaze", "Powers up Fire-type moves when the Pokemon's HP is low."));
    charmander.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(charmander);

    //Charmeleon 
    Stats charmelStats(58,64,58,80,65,80);

    charmelStats.setIVs(0,0,0,0,0,0);
    charmelStats.setEVs(0,0,0,0,0,0);
    charmelStats.setNature("Serious");

    Pokemon charmeleon("Charmeleon",5,"Fire","","Kanto","When it swings its burning tail, it elevates the temperature to unbearably high levels.",charmelStats);

    charmeleon.addAbility(Ability("Blaze", "Powers up Fire-type moves when the Pokemon's HP is low."));
    charmeleon.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(charmeleon);

    //Charizard
    Stats charizStats(78,84,78,109,85,100);

    charizStats.setIVs(0,0,0,0,0,0);
    charizStats.setEVs(0,0,0,0,0,0);
    charizStats.setNature("Serious");

    Pokemon charizard("Charizard",6,"Fire","Flying","Kanto","Breathing intense, hot flames, it can melt almost anything. Its breath inflicts terrible pain on enemies.",charizStats);

    charizard.addAbility(Ability("Blaze", "Powers up Fire-type moves when the Pokemon's HP is low."));
    charizard.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(charizard);

    //Squirtle
    Stats squirtStats(44,48,65,50,64,43);

    squirtStats.setIVs(0,0,0,0,0,0);
    squirtStats.setEVs(0,0,0,0,0,0);
    squirtStats.setNature("Serious");

    Pokemon squirtle("Squirtle",7,"Water","","Kanto","Shoots water at prey while in the water. Withdraws into its shell when in danger.",squirtStats);

    squirtle.addAbility(Ability("Torrent", "Powers up Water-type moves when the Pokemon's HP is low."));
    squirtle.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(squirtle);

    //Wartortle
    Stats wartStats(59,63,80,65,80,58);

    wartStats.setIVs(0,0,0,0,0,0);
    wartStats.setEVs(0,0,0,0,0,0);
    wartStats.setNature("Serious");

    Pokemon wartortle("Wartortle",8,"Water","","Kanto","It cleverly controls its furry ears and tail to maintain its balance while swimming.",wartStats);

    wartortle.addAbility(Ability("Torrent", "Powers up Water-type moves when the Pokemon's HP is low."));
    wartortle.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(wartortle);
    
    //Blastoise
    Stats blastStats(79,83,100,85,105,78);

    blastStats.setIVs(0,0,0,0,0,0);
    blastStats.setEVs(0,0,0,0,0,0);
    blastStats.setNature("Serious");

    Pokemon blastoise("Blastoise",9,"Water","","Kanto","Once it takes aim at its enemy, it blasts out water with even more force than a fire hose",blastStats);

    blastoise.addAbility(Ability("Torrent", "Powers up Water-type moves when the Pokemon's HP is low."));
    blastoise.addLocation(Location("First partner pokemon only"));

    pokedex.push_back(blastoise);

    //Caterpie
    Stats caterStats(45,30,35,20,20,45);

    caterStats.setIVs(0,0,0,0,0,0);
    caterStats.setEVs(0,0,0,0,0,0);
    caterStats.setNature("Serious");

    Pokemon caterpie("Caterpie",10,"Bug","","Kanto","If you touch the feeler on top of its head, it will release a horrible stink to protect itself.",caterStats);

    caterpie.addAbility(Ability("Shield Dust", "Blocks the additional effects of attacks taken"));
    caterpie.addLocation(Location("Viridian Forest"));

    pokedex.push_back(caterpie);
    
    //Metapod
    Stats metaStats(50,20,55,25,25,30);

    metaStats.setIVs(0,0,0,0,0,0);
    metaStats.setEVs(0,0,0,0,0,0);
    metaStats.setNature("Serious");

    Pokemon metapod("Metapod",11,"Bug","","Kanto","It prepares for evolution by hardening its shell as much as possible to protect its soft body.",metaStats);

    metapod.addAbility(Ability("Shed Skin", "The Pokemon may heal its own status conditions."));
    metapod.addLocation(Location("Viridian Forest"));

    pokedex.push_back(metapod);
    
    //Butterfree
    Stats butterStats(60,45,50,80,80,70);

    butterStats.setIVs(0,0,0,0,0,0);
    butterStats.setEVs(0,0,0,0,0,0);
    butterStats.setNature("Serious");

    Pokemon butterfree("Butterfree",12,"Bug","Flying","Kanto","In battle, it flaps its wings at high speed to release highly toxic dust into the air.",butterStats);

    butterfree.addAbility(Ability("Compound Eyes", "Boosts the Pokemon's accuracy."));
    butterfree.addLocation(Location("Evolve Metapod"));

    pokedex.push_back(butterfree);
    
    //Weedle
    Stats weedStats(40,35,30,20,20,50);

    weedStats.setIVs(0,0,0,0,0,0);
    weedStats.setEVs(0,0,0,0,0,0);
    weedStats.setNature("Serious");

    Pokemon weedle("Weedle",13,"Bug","","Kanto","Often found in forests, eating leaves. It has a sharp venmous stinger on its head.",weedStats);

    weedle.addAbility(Ability("Shield Dust", "Blocks the additional effects of attacks taken"));
    weedle.addLocation(Location("Viridian Forest"));

    pokedex.push_back(weedle);

    //Kakuna
    Stats kakuStats(45,25,50,25,25,35);

    kakuStats.setIVs(0,0,0,0,0,0);
    kakuStats.setEVs(0,0,0,0,0,0);
    kakuStats.setNature("Serious");

    Pokemon kakuna("Kakuna",14,"Bug","","Kanto","Able to move only slightly. When endangered, it may stick out its stinger and poison its enemy.",kakuStats);

    kakuna.addAbility(Ability("Shed Skin", "The Pokemon may heal its own status conditions."));
    kakuna.addLocation(Location("Viridian Forest"));

    pokedex.push_back(kakuna);

    //Beedrill
    Stats beeStats(65,80,40,45,80,75);

    beeStats.setIVs(0,0,0,0,0,0);
    beeStats.setEVs(0,0,0,0,0,0);
    beeStats.setNature("Serious");

    Pokemon beedrill("Beedrill",15,"Bug","Poison","Kanto","It can take down any opponent with its poerful poison stingers. It sometimes attacks in swarms.",beeStats);

    beedrill.addAbility(Ability("Swarm", "Powers up Bug-type moves in a pinch."));
    beedrill.addLocation(Location("Evolve Kakuna"));

    pokedex.push_back(beedrill);

    //Pidgey
    Stats pidgeyStats(40,45,40,35,35,56);

    pidgeyStats.setIVs(0,0,0,0,0,0);
    pidgeyStats.setEVs(0,0,0,0,0,0);
    pidgeyStats.setNature("Serious");

    Pokemon pidgey("Pidgey",16,"Normal","Flying","Kanto","Very docile. If attacked, it will often kick up sand to protect itself rather than fight back.",pidgeyStats);

    pidgey.addAbility(Ability("Keen Eye", "Prevents loss of accuracy."));
    pidgey.addLocation(Location("Routes 1 - 3, 5 - 8, 12-15, 21, 24 and 25"));

    pokedex.push_back(pidgey);

    //Pidgeotto
    Stats pidgeottoStats(63,55,50,50,50,71);

    pidgeottoStats.setIVs(0,0,0,0,0,0);
    pidgeottoStats.setEVs(0,0,0,0,0,0);
    pidgeottoStats.setNature("Serious");

    Pokemon pidgeotto("Pidgeotto",17,"Normal","Flying","Kanto","It slowly flies in a cicular pattern, all the while keeping a sharp lookout for prey.",pidgeottoStats);

    pidgeotto.addAbility(Ability("Keen Eye", "Prevents loss of accuracy."));
    pidgeotto.addLocation(Location("Routes 14, 15 and 21"));

    pokedex.push_back(pidgeotto);

    //Pidgeot
    Stats pidgeotStats(83,80,75,70,70,91);

    pidgeotStats.setIVs(0,0,0,0,0,0);
    pidgeotStats.setEVs(0,0,0,0,0,0);
    pidgeotStats.setNature("Serious");

    Pokemon pidgeot("Pidgeot",18,"Normal","Flying","Kanto","It spreads its beautiful wings wide to frighten its enemies. It can fly at Mach 2 speed.",pidgeotStats);

    pidgeot.addAbility(Ability("Keen Eye", "Prevents loss of accuracy."));
    pidgeot.addLocation(Location("Evolve Pidgeotto"));

    pokedex.push_back(pidgeot);

    //Menu
    int choice;

    do {
        cout << "\n===== Pokedex System =====\n";
        cout << "1. Search by Pokemon Name\n";
        cout << "2. Search by Pokemon ID\n";
        cout << "3. View All Pokemon\n";
        cout << "4. Exit\n";
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
        else if (choice == 3) {
        listAllPokemon(pokedex);
        }

    } while (choice != 4);

    return 0;
}