#ifndef HW8_MAN_H
#define HW8_MAN_H

#include "Unit.h"

class Man : public virtual Unit {
public:
    explicit Man(const std::string& n);
    void sayHello(Unit&);
};

#endif //HW8_MAN_H
