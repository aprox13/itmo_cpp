#ifndef HW8_BEAR_H
#define HW8_BEAR_H

#include "Animal.h"

class Bear : public Animal {
public:
    explicit Bear(const std::string& n);
    void giveHoney(Unit&, int);
    void sound() override;
};


#endif //HW8_BEAR_H
