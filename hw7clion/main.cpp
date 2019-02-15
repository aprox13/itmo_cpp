#include <iostream>
#include "Array.h"
#include "NoAssign.h"


bool less(int& a, int& b) {
    return a < b;
}

struct Cmp {
    bool operator()(int& a, int& b) {
        return a > b;
    }
};


int main() {
    NoAssign j(5);
    Array<NoAssign> arr01(5, j);
    Array<NoAssign> arr0(15, j);
    arr0 = arr01;
    for (int i = 0; i < arr0.size(); i++) {
        std::cout << arr0[i] << " ";
    }

    Array<int> arr(10);
    std::cout << std::endl;
    for (int i = 0; i < arr.size(); i++) {

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < arr.size(); i++) {

        arr[i] = 2 * i;
    }
    arr[0] = 10;
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Minimum(func): " << minimum(arr, less);
    std::cout << std::endl;
    std::cout << "Maximum(struct): " << minimum(arr, Cmp());
    std::cout << std::endl;
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    std::cout << "Flatten: ";
    flatten(ints, std::cout);
    std::cout << std::endl << "Flatten 2: ";
    auto aa = Array<Array<int>>(2, ints);
    flatten(aa, std::cout);
    std::cout << std::endl << "Flatten double: ";
    flatten(Array<double>(2, 1.6), std::cout);
    return 0;
}