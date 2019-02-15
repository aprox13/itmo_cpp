//
// Created by Roman on 27.11.2018.
//

#ifndef HW8_PIG_H
#define HW8_PIG_H
#include "Animal.h"

class Pig : public Animal {
public:
    explicit Pig(const std::string& n);
    void angryGrunt(Unit&, int);
    void sound() override;
};


#endif //HW8_PIG_H
