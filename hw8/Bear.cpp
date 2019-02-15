#include "Bear.h"

void Bear::sound() {
    std::cout << "Roar";
}

void Bear::giveHoney(Unit& who, int honeyCount) {
    who.heal(honeyCount);
}

Bear::Bear(const std::string& n) : Unit(n), Animal(n) {}
