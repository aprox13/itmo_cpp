#include <iostream>
#include "Fraction.h"
#include <string>

void out(const Fraction& f) {
    std::cout << f << std::endl;
}

void out(const char* title) {
    std::cout << title << std::endl;
}

void out(bool f) {
    std::cout << std::boolalpha << f << std::endl;
}

void out(size_t size){
    std::cout << size << std::endl;
}

int main() {
    Fraction f(10, 2);
    out("output");
    std::cout << f << std::endl;
    ~f;
    out("normalize");
    std::cout << f << std::endl;

    Fraction f1(10, 3), f2(10, 10);
    out("prisvaivanie");
    f2 = f1;
    out(f2);

    out("unary +/-");
    out(f1);
    out(+f1);
    out(-f1);

    out("++ postfix and prefix");
    out(f);
    out(f++);
    out(++f);

    out("-- postfix and prefix");
    out(f);
    out(f--);
    out(--f);
    out("f = 1/n; --n; --n; ++n; ++n");
    Fraction f3(1, 9);
    out(f3);
    out(--f3);
    out(--f3);
    out(++f3);
    out(++f3);

    out("operator f1 + f2");
    out(f1);
    out(f2);
    out(f1 + f2);
    f1++;
    f2++;
    out(f1);
    out(f2);
    out(((f1 + f2)));

    out("op - * /");
    Fraction f4(25, 4), f5(25, 3);
    out(f5 - f4);
    out(f5 * f4);
    out(f4 / f4); // NOLINT
    out("+= -= *= /=");
    out(f4);
    out(f5);
    f4 += f5;
    out(f4);
    f4 -= f5;
    out(f4);
    f4 *= f5;
    out(f4);
    f4 /= f5;
    out(f4);
    out("== != > < >= <=");
    Fraction f6(10, 2), f7(15, 3), f8(1, 9);
    out(f6 == f7);
    out(f6 != f8);
    out(f6 > f8);
    out(f6 < f8);
    out(f6 <= f8);
    out(f6 >= f8);
    out("&ui |ui  ^ui <<ui >>ui &= |= <<= >>=");
    Fraction f10(10), f11(11), f12(12), f13(13), f14(14);
    size_t t = 2;
    out(f10 & t);
    out(f11 | t);
    out(f12 ^ t);
    out(f13 >> t);
    out(f14 << t);
    out(f10 &= t);
    out(f11 |= t);
    out(f12 ^= t);
    out(f13 >>= t);
    out(f14 <<= t);
    out("% %=");
    Fraction f15(5, 4), f16(1);
    out(f15 % f16);
    out(f15 %= f16);
    out("Dummy sum");
    out(f15);
    out(f15[-f15]);
    out("bool && ||");
    Fraction f17(0), f18(18);
    auto q = f17();
    auto p = f18();
    out(q);
    out(p);
    out(f17 || f18);
    out(f17 && f18);
    out(",");
    Fraction res = (Fraction(5, 4), Fraction(1));
    out(res);
    // ### TOTAL 41 ###
    return 0;
}