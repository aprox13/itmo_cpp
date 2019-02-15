#include "Animal.h"

void Animal::sound() {
    std::cout << "I'm a unit!";
}

Animal::Animal(const std::string& n) : Unit(n) {}
