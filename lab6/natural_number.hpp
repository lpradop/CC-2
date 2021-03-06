//Natural Numbers representation for moar typesafety
#pragma once
#include <iostream>
class NaturalNumber
{
private:
    unsigned long long number_;

public:
    NaturalNumber(const long long number=0);
    NaturalNumber operator++();
    NaturalNumber operator++(int);
    NaturalNumber operator--();
    NaturalNumber operator--(int);
    NaturalNumber &operator+=(const NaturalNumber &other);
    template <typename CastType>
    operator CastType() const;

    friend int operator+(const NaturalNumber a, const int b);
    friend int operator+(const int a, const NaturalNumber b);
    friend float operator+(const NaturalNumber a, const float b);
    friend float operator+(const float a, const NaturalNumber b);
    friend NaturalNumber operator+(NaturalNumber a,const NaturalNumber &b);
    friend std::ostream& operator<<(std::ostream& os, const NaturalNumber& number);
    
};


