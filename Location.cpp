#include "Location.h"


Location::Location() {
    placeName = "";
}

Location::Location(string placeName) {
    this->placeName = placeName;
}


void Location::display() {
    cout << "- " << placeName << endl;
}