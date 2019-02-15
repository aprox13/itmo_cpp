#include <iostream>
#include "String.h"
#include "hw5/String.h"

#include "hw6/Group.h"


int main() {
    String mama = "mama papa";
    std::cout << mama << std::endl;

    String filter(5, 's');
    std::cout << filter << std::endl;

    String fromMama(mama);
    std::cout << "From: '" << mama << "', got: '" << fromMama << "'" << std::endl;

    String testEq = String("test eq");
    String fromstr = testEq;
    std::cout << "From: '" << testEq << "', got: '" << fromstr << "'" << std::endl;


    String append1 = "Hello, ", append2 = "World!";
    std::cout << "'" << append1 << "'.append('" << append2 << "')" << std::endl;
    append1.append(append2);
    std::cout << append1 << std::endl;
    std::cout << "'" << append1 << "'.append('" << append1 << "')" << std::endl;
    append1.append(append1);
    std::cout << append1 << std::endl;
    return 0;
}