#include "Fraction.h"
#include <bits/stdc++.h>
#include <utility>


Fraction::Fraction(int n, int d) : mNumerator(static_cast<size_t>((n))),
                                   mDenominator(static_cast<size_t>(d)),
                                   mSign(n * d > 0 ? POSITIVE : NEGATIVE) {}


Fraction::Fraction(size_t n, size_t d, int sign) : mNumerator(n),
                                                   mDenominator(d),
                                                   mSign(sign) {}

Fraction::Fraction() : mNumerator(0),
                       mDenominator(0),
                       mSign(1) {}

Fraction::Fraction(const Fraction& f) {
    mSign = f.mSign;
    mNumerator = f.mNumerator;
    mDenominator = f.mDenominator;
}

template<class T>
void swap(T& a, T& b) {
    T c(std::move(a));
    a = std::move(b);
    b = std::move(c);
}

Fraction& Fraction::operator~() {
    int b = (mDenominator);
    int a = (mNumerator);
    while (b) {
        a %= b;
        swap(a, b);
    }
    if (a != 0) {
        mNumerator /= a;
        mDenominator /= a;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    if (f.mSign == Fraction::NEGATIVE && f.mNumerator != 0) {
        os << "-";
    }
    os << f.mNumerator;
    if (f.mDenominator != 1 && f.mNumerator != 0)
        os << " / " << f.mDenominator;
    return os;
}

Fraction& Fraction::operator=(const Fraction& v) {
    if (&v == this) {
        return *this;
    }
    this->mNumerator = v.mNumerator;
    this->mDenominator = v.mDenominator;
    this->mSign = v.mSign;
    return *this;
}

Fraction Fraction::operator+() const {
    return Fraction(*this);
}

Fraction Fraction::operator-() const {
    return Fraction(mNumerator, mDenominator, -mSign);
}

const Fraction Fraction::operator++(int) { // postfix
    auto f = Fraction(*this);
    ++(*this);
    return f;
}

Fraction& Fraction::operator++() {
    if (mSign == NEGATIVE) {
        this->mNumerator--;
    } else {
        this->mNumerator++;
    }
    if (mNumerator == 0) {
        mSign = POSITIVE;
    }
    return *this;
}

const Fraction Fraction::operator--(int) { // postfix
    auto f = Fraction(*this);
    --(*this);
    return f;
}

Fraction& Fraction::operator--() {
    if (mSign == POSITIVE) {
        this->mNumerator--;
    } else {
        this->mNumerator++;
    }
    if (mNumerator == 0) {
        mSign = NEGATIVE;
    }
    return *this;
}

bool Fraction::operator!() const {
    return *this != Fraction(0);
}

Fraction Fraction::operator+(const Fraction& second) const {

    auto cN = mSign * static_cast<int>(mNumerator);
    auto cD = static_cast<int>(mDenominator);
    auto sN = second.mSign * static_cast<int>(second.mNumerator);
    auto sD = static_cast<int>(second.mDenominator);
    int numerator = cN * sD + cD * sN;
    int denominator = sD * cD;
    Fraction F = Fraction(numerator, denominator);
    return ~F;
}

Fraction Fraction::operator-(const Fraction& second) const {

    Fraction F = Fraction(*this) + (-second);
    return ~F;
}

Fraction Fraction::operator*(const Fraction& second) const {
    Fraction F = Fraction(mNumerator * second.mNumerator, mDenominator * second.mDenominator);
    return ~F;
}

Fraction Fraction::operator/(const Fraction& second) const {
    Fraction F = Fraction(*this) * Fraction(second.mDenominator, second.mNumerator, second.mSign);
    ~F;
    return F;
}

Fraction& Fraction::operator+=(const Fraction& second) {
    (*this) = (*this) + second;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& second) {
    (*this) = (*this) - second;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& second) {
    (*this) = (*this) * second;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& second) {
    (*this) = (*this) / second;
    return *this;
}

bool Fraction::operator==(const Fraction& bb) const {
    Fraction a = Fraction(*this);
    Fraction b = Fraction(bb);
    ~a;
    ~b;
    return a.mDenominator == b.mDenominator && a.mNumerator == b.mNumerator &&
           (a.mSign == b.mSign || a.mNumerator == 0);
}

bool Fraction::operator!=(const Fraction& b) const {
    return !(*this == b);
}

bool Fraction::operator>(const Fraction& bb) const {
    Fraction f = (~Fraction(*this)) - (~Fraction(bb));
    return f.mSign == POSITIVE && f.mNumerator != 0;
}

bool Fraction::operator<(const Fraction& b) const {
    return b > *this;
}


bool Fraction::operator<=(const Fraction& b) const {
    return !(b < *this);
}

bool Fraction::operator>=(const Fraction& b) const {
    return !(b > *this);
}


Fraction Fraction::operator&(const size_t& second) const {
    Fraction F = Fraction(mNumerator & second, mDenominator, mSign);
    return ~F;
}

Fraction Fraction::operator|(const size_t& second) const {
    Fraction F = Fraction(mNumerator | second, mDenominator, mSign);
    return ~F;
}

Fraction Fraction::operator^(const size_t& second) const {
    Fraction F = Fraction(mNumerator ^ second, mDenominator, mSign);
    return ~F;
}

Fraction Fraction::operator<<(const size_t& second) const {
    Fraction F = Fraction(mNumerator << second, mDenominator, mSign);
    return ~F;
}

Fraction Fraction::operator>>(const size_t& second) const {
    Fraction F = Fraction(mNumerator >> second, mDenominator, mSign);
    return ~F;
}

Fraction& Fraction::operator&=(const size_t& second) {
    *this = *this & second;
    return *this;
}

Fraction& Fraction::operator|=(const size_t& second) {
    *this = *this | second;
    return *this;
}

Fraction& Fraction::operator^=(const size_t& second) {
    *this = *this ^ second;
    return *this;
}

Fraction& Fraction::operator<<=(const size_t& second) {
    *this = *this << second;
    return *this;
}

Fraction& Fraction::operator>>=(const size_t& second) {
    *this = *this >> second;
    return *this;
}


Fraction Fraction::operator%(const Fraction& a) const {
    Fraction f = (*this) / a;
    return Fraction(f.mNumerator % f.mDenominator, f.mDenominator, POSITIVE);
}

Fraction& Fraction::operator%=(const Fraction& a) {
    *this = (*this) % a;
    return *this;
}

Fraction Fraction::operator[](const Fraction& a) const {
    int num = static_cast<int>(mNumerator) * mSign + static_cast<int>(a.mNumerator) * a.mSign;
    int den = mDenominator + a.mDenominator;
    return Fraction(num, den);
}

Fraction::operator bool() const {
    return mNumerator != 0;
}

bool Fraction::operator&&(const Fraction& a) const {
    return a() && (*this)();
}

bool Fraction::operator||(const Fraction& a) const {
    return a() || (*this)();
}

Fraction Fraction::operator,(const Fraction& a) const {
    Fraction f = *this / a;
    Fraction d = *this % a;
    return ~(f - d);
}

bool Fraction::operator()() const {
    return bool(*this);
}

Fraction& Fraction::operator*() {
    return *this;
}

Fraction* Fraction::operator&() {
    return (this);
}

Fraction* Fraction::operator->() {
    return this;
}




