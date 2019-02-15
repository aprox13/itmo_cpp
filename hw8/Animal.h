#ifndef HW8_ANIMAL_H
#define HW8_ANIMAL_H

#include "Unit.h"

class Animal : public virtual Unit {
public:
    explicit Animal(const std::string& n);
    virtual void sound();
};


#endif //HW8_ANIMAL_H
