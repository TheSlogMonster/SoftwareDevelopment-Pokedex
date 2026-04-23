#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <iostream>
using namespace std;

class Location {
private:
    string placeName;

public:
    Location();
    Location(string placeName);

    void display();
};

#endif