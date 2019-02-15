#pragma once

#include <iostream>
#include <string>
#include <utility>

class Unit {
public:
    std::string name;
    int hp;
    int mood;

    explicit Unit(const std::string& name);
    void heal(int);
    void receiveDamage(int);
    void giveDamage(Unit&, int);

    virtual ~Unit() = default;
};


