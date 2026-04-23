#ifndef SEARCH_H
#define SEARCH_H
#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"
#include <iostream>

string toLowerCase(std::string str);
void searchByName(std::vector<Pokemon>& list, std::string name);
void searchByID(std::vector<Pokemon>& list, int id);

#endif