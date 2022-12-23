#pragma once

#include <iostream>
using std::string;
class Weapon
{
public:
    string name;
    int damage;
    float weight;
    Weapon();
    Weapon(string name, int damage, float weight);
};

