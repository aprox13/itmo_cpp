//
// Created by Roman on 27.11.2018.
//

#ifndef HW7CLION_NOASSIGN_H
#define HW7CLION_NOASSIGN_H

#include <iostream>

struct NoAssign {
    int data ;

    NoAssign(const NoAssign&);
    NoAssign() = delete;
    explicit NoAssign(int data);

    friend std::ostream& operator<<(std::ostream&, const NoAssign&);
};


#endif //HW7CLION_NOASSIGN_H
