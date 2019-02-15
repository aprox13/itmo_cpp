//
// Created by Roman on 27.11.2018.
//

#include "NoAssign.h"

NoAssign::NoAssign(const NoAssign& from) : data(from.data) {}
NoAssign::NoAssign(int from) : data(from) {}

std::ostream& operator<<(std::ostream& os, const NoAssign& na) {
    os << na.data;
    return os;
}
