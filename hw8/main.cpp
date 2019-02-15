#include <iostream>
#include <string>
#include <typeinfo>
#include "ManBearPig.h"

typedef int* (* (* ComplexFunction)(int, int (*)(double)))(char const*);

template<class T, class V>
bool compare(const T& first, const T& second, V (T::*method)() const) {
    return (first.*method)() < (second.*method)();
};

template<typename T>
bool isSameObject(T const* p, T const* q) {
    return (dynamic_cast<void const*>(p) == dynamic_cast<void const*>(q));
}

int main() {

    std::string a = "mama";
    std::string b = "papa";

    ManBearPig mbp1("1"), mbp2("2");
    mbp1.sound();
    std::cout << std::endl;


    std::cout << std::boolalpha << compare(a, b, &std::string::size) << std::endl;

    std::cout << std::boolalpha << compare(a, b + b, &std::string::size) << std::endl;

    std::cout << std::endl;

    std::cout << std::boolalpha << isSameObject(&mbp1, &mbp2) << std::endl
              << std::boolalpha << isSameObject(&mbp1, &mbp1) << std::endl
              << std::boolalpha << isSameObject((Unit*) (Pig*) &mbp1, (Unit*) (Bear*) &mbp2) << std::endl
              << std::boolalpha << isSameObject((Unit*) (Pig*) &mbp1, (Unit*) (Bear*) &mbp1) << std::endl;
    return 0;
}