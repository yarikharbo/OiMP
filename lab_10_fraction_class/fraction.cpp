#include "Fraction.h"
#include <algorithm>
#include <cmath>

int64_t GCD(int64_t a, int64_t b) {
    while (a != 0 && b != 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return std::max(a, b);
}


void Fraction::check() {
    if (denum == 0) {
        throw std::invalid_argument("Denum can't be zero");
    }
    int64_t gcd = GCD(num, denum);
    if (gcd > 1) {
        num /= gcd;
        denum /= gcd;
    }
    if (denum < 0) {
        num = -num;
        denum = -denum;
    }
}

Fraction::Fraction() : num(0), denum(1) {}

Fraction::Fraction(int64_t num) : num(num), denum(1) {}

Fraction::Fraction(int64_t num, int64_t denum) : num(num), denum(denum) {
    check();
}

int64_t Fraction::getNum() const {
    return num;
}

int64_t Fraction::getDenum() const {
    return denum;
}

void Fraction::setNum(int64_t new_num) {
    num = new_num;
    check();
}

void Fraction::setDenum(int64_t new_denum) {
    denum = new_denum;
    check();
}

long double Fraction::toDouble() const {
    return (long double)(num) / denum;
}

Fraction Fraction::operator+(const Fraction& other) {
    int64_t new_num = num * other.denum + denum * other.num;
    int64_t new_denum = denum * other.denum;
    return Fraction(new_num, new_denum);
}

Fraction Fraction::operator-(const Fraction& other) {
    int64_t new_num = num * other.denum - denum * other.num;
    int64_t new_denum = denum * other.denum;
    return Fraction(new_num, new_denum);
}

Fraction Fraction::operator*(const Fraction& other) {
    return Fraction(num * other.num, denum * other.denum);
}

Fraction Fraction::operator/(const Fraction& other) {
    if (other.num == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Fraction(num * other.denum, denum * other.num);
}

Fraction Fraction::operator-() {
    return Fraction(-num, denum);
}

Fraction Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        num = other.num;
        denum = other.denum;
    }
    return *this;
}

bool Fraction::operator==(const Fraction& other) {
    return num * other.denum == denum * other.num;
}

bool Fraction::operator!=(const Fraction& other) {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) {
    return num * other.denum < denum * other.num;
}

bool Fraction::operator>(const Fraction& other) {
    return num * other.denum > denum * other.num;
}

bool Fraction::operator<=(const Fraction& other) {
    return num * other.denum <= denum * other.num;
}

bool Fraction::operator>=(const Fraction& other) {
    return num * other.denum >= denum * other.num;
}

Fraction Fraction::operator+=(const Fraction& other) {
    *this = *this + other;
    return *this;
}

Fraction Fraction::operator-=(const Fraction& other) {
    *this = *this - other;
    return *this;
}

Fraction Fraction::operator*=(const Fraction& other) {
    *this = *this * other;
    return *this;
}

Fraction Fraction::operator/=(const Fraction& other) {
    *this = *this / other;
    return *this;
}

Fraction Fraction::operator++() {
    num += denum;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction Fraction::operator--() {
    num -= denum;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    --(*this);
    return temp;
}

Fraction Fraction::operator!() {
    std::swap(num, denum);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fraction& result) {
    out << result.getNum() << "/" << result.getDenum();
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& result) {
    char slash;
    in >> result.num;
    in >> slash;
    in >> result.denum;
    result.check();
    return in;
}
Fraction IntToFraction(int64_t number) {
    return Fraction(number, 1);
}
Fraction DoubleToFraction(long double number) {
    return Fraction(static_cast<int64_t>(number * 10000), 10000);
}
