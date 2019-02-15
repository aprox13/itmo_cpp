#include "Pig.h"

void Pig::angryGrunt(Unit& who, int count) {
    who.mood -= count;
}

void Pig::sound() {
    std::cout << "Oink";
}

Pig::Pig(const std::string& n) : Unit(n), Animal(n) {}

