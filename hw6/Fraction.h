#pragma once

#include <iostream>

class Fraction {
public:
    explicit Fraction(int, int = 1);
    Fraction();
    Fraction(const Fraction&);
    Fraction& operator=(const Fraction& f);

    // unary
    Fraction&      operator~(); //normalize
    Fraction       operator+() const;
    Fraction       operator-() const;
    const Fraction operator++(int); // postfix
    Fraction&      operator++();
    const Fraction operator--(int); // postfix
    Fraction&      operator--();
    bool           operator!() const ;
    bool           operator()() const;
    explicit       operator bool() const;
    Fraction&      operator*();
    Fraction*      operator&();
    Fraction*      operator->();

    // binary
    Fraction  operator[](const Fraction&) const; // dummy sum
    Fraction  operator+(const Fraction&) const;
    Fraction  operator-(const Fraction&) const;
    Fraction  operator*(const Fraction&) const;
    Fraction  operator/(const Fraction&) const;
    Fraction& operator+=(const Fraction&);
    Fraction& operator-=(const Fraction&);
    Fraction& operator*=(const Fraction&);
    Fraction& operator/=(const Fraction&);
    bool      operator==(const Fraction&) const;
    bool      operator!=(const Fraction&) const;
    bool      operator>(const Fraction&) const;
    bool      operator<(const Fraction&) const;
    bool      operator>=(const Fraction&) const;
    bool      operator<=(const Fraction&) const;
    Fraction  operator&(const size_t&) const;
    Fraction  operator|(const size_t&) const;
    Fraction  operator^(const size_t&) const;
    Fraction  operator>>(const size_t&) const;
    Fraction  operator<<(const size_t&) const;
    Fraction& operator&=(const size_t&);
    Fraction& operator|=(const size_t&);
    Fraction& operator^=(const size_t&);
    Fraction& operator>>=(const size_t&);
    Fraction& operator<<=(const size_t&);
    Fraction  operator%(const Fraction&) const;
    Fraction& operator%=(const Fraction&);
    bool      operator&&(const Fraction&) const;
    bool      operator||(const Fraction&) const;
    Fraction  operator,(const Fraction&) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

private:
    size_t           mNumerator;
    size_t           mDenominator;
    int              mSign;
    const static int POSITIVE = 1;
    const static int NEGATIVE = -1;

    Fraction(size_t n, size_t d, int sign);
};
