#ifndef HW8_MANBEARPIG_H
#define HW8_MANBEARPIG_H

#include "Man.h"
#include "Bear.h"
#include "Pig.h"


class ManBearPig : public Man, public Bear, public Pig {
public:
    explicit ManBearPig(const std::string& n) : Unit(n), Man(n), Bear(n), Pig(n) {}
    void sound() override;
};

#endif //HW8_MANBEARPIG_H
