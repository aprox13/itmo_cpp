#include "Unit.h"
#include <iostream>
#include <utility>

void Unit::heal(int sleepTime) {
    hp += sleepTime * 5;
    mood += 10;
}

void Unit::receiveDamage(int dmg) {
    hp -= dmg;
    mood--;
}

void Unit::giveDamage(Unit& who, int dmg) {
    who.hp -= dmg;
    who.mood++;
}

Unit::Unit(const std::string& n) {
    name = n;
}





