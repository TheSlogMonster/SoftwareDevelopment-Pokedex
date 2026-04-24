#include "TypeChart.h"

float getEffectiveness(string atk, string def) {

    // Normal
    if (atk == "Normal") {
        if (def == "Rock" || def == "Steel") return 0.5;
        if (def == "Ghost") return 0.0;
    }

    // Fire
    else if (atk == "Fire") {
        if (def == "Grass" || def == "Ice" || def == "Bug" || def == "Steel") return 2.0;
        if (def == "Fire" || def == "Water" || def == "Rock" || def == "Dragon") return 0.5;
    }

    // Wwater
    else if (atk == "Water") {
        if (def == "Fire" || def == "Ground" || def == "Rock") return 2.0;
        if (def == "Water" || def == "Grass" || def == "Dragon") return 0.5;
    }

    // Electric
    else if (atk == "Electric") {
        if (def == "Water" || def == "Flying") return 2.0;
        if (def == "Electric" || def == "Grass" || def == "Dragon") return 0.5;
        if (def == "Ground") return 0.0;
    }

    // Grass
    else if (atk == "Grass") {
        if (def == "Water" || def == "Ground" || def == "Rock") return 2.0;
        if (def == "Fire" || def == "Grass" || def == "Poison" || def == "Flying" ||
            def == "Bug" || def == "Dragon" || def == "Steel") return 0.5;
    }

    // Ice
    else if (atk == "Ice") {
        if (def == "Grass" || def == "Ground" || def == "Flying" || def == "Dragon") return 2.0;
        if (def == "Fire" || def == "Water" || def == "Ice" || def == "Steel") return 0.5;
    }

    // Fighting
    else if (atk == "Fighting") {
        if (def == "Normal" || def == "Ice" || def == "Rock" || def == "Dark" || def == "Steel") return 2.0;
        if (def == "Poison" || def == "Flying" || def == "Psychic" || def == "Bug" || def == "Fairy") return 0.5;
        if (def == "Ghost") return 0.0;
    }

    // Poison
    else if (atk == "Poison") {
        if (def == "Grass" || def == "Fairy") return 2.0;
        if (def == "Poison" || def == "Ground" || def == "Rock" || def == "Ghost") return 0.5;
        if (def == "Steel") return 0.0;
    }

    // Ground
    else if (atk == "Ground") {
        if (def == "Fire" || def == "Electric" || def == "Poison" || def == "Rock" || def == "Steel") return 2.0;
        if (def == "Grass" || def == "Bug") return 0.5;
        if (def == "Flying") return 0.0;
    }

    // Flying
    else if (atk == "Flying") {
        if (def == "Grass" || def == "Fighting" || def == "Bug") return 2.0;
        if (def == "Electric" || def == "Rock" || def == "Steel") return 0.5;
    }

    // Psychic
    else if (atk == "Psychic") {
        if (def == "Fighting" || def == "Poison") return 2.0;
        if (def == "Psychic" || def == "Steel") return 0.5;
        if (def == "Dark") return 0.0;
    }

    // Bug
    else if (atk == "Bug") {
        if (def == "Grass" || def == "Psychic" || def == "Dark") return 2.0;
        if (def == "Fire" || def == "Fighting" || def == "Poison" ||
            def == "Flying" || def == "Ghost" || def == "Steel" || def == "Fairy") return 0.5;
    }

    // Rock
    else if (atk == "Rock") {
        if (def == "Fire" || def == "Ice" || def == "Flying" || def == "Bug") return 2.0;
        if (def == "Fighting" || def == "Ground" || def == "Steel") return 0.5;
    }

    // Ghost
    else if (atk == "Ghost") {
        if (def == "Psychic" || def == "Ghost") return 2.0;
        if (def == "Dark") return 0.5;
        if (def == "Normal") return 0.0;
    }

    // Dragon
    else if (atk == "Dragon") {
        if (def == "Dragon") return 2.0;
        if (def == "Steel") return 0.5;
        if (def == "Fairy") return 0.0;
    }

    // Dark
    else if (atk == "Dark") {
        if (def == "Psychic" || def == "Ghost") return 2.0;
        if (def == "Fighting" || def == "Dark" || def == "Fairy") return 0.5;
    }

    // Steel
    else if (atk == "Steel") {
        if (def == "Ice" || def == "Rock" || def == "Fairy") return 2.0;
        if (def == "Fire" || def == "Water" || def == "Electric" || def == "Steel") return 0.5;
    }

    // Fairy
    else if (atk == "Fairy") {
        if (def == "Fighting" || def == "Dragon" || def == "Dark") return 2.0;
        if (def == "Fire" || def == "Poison" || def == "Steel") return 0.5;
    }

    return 1.0;
}