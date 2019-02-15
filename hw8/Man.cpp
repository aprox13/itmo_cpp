#include "Man.h"

void Man::sayHello(Unit& unit) {
    unit.mood++;
}

Man::Man(const std::string& n) : Unit(n) {}
