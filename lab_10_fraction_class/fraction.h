#ifndef FRACTION_H
#define FRACTION_H

#include <cstdint>
#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int64_t num;
    int64_t denum;
    void check();
public:
    Fraction();
    Fraction(int64_t num);
    Fraction(int64_t num, int64_t denum);

    int64_t getNum() const;
    int64_t getDenum() const;
    void setNum(int64_t new_num);
    void setDenum(int64_t new_denum);

    long double toDouble() const;

    Fraction operator+(const Fraction& other);
    Fraction operator-(const Fraction& other);
    Fraction operator*(const Fraction& other);
    Fraction operator/(const Fraction& other);

    Fraction operator-();
    Fraction operator!();

    Fraction operator=(const Fraction& other);

    bool operator==(const Fraction& other);
    bool operator!=(const Fraction& other);
    bool operator<(const Fraction& other);
    bool operator>(const Fraction& other);
    bool operator<=(const Fraction& other);
    bool operator>=(const Fraction& other);

    Fraction operator+=(const Fraction& other);
    Fraction operator-=(const Fraction& other);
    Fraction operator*=(const Fraction& other);
    Fraction operator/=(const Fraction& other);

    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& result);
    friend std::istream& operator>>(std::istream& in, Fraction& result);
};

Fraction IntToFraction(int64_t number);
Fraction DoubleToFraction(long double number);

int64_t GCD(int64_t a, int64_t b);

#endif
