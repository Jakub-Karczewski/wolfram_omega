#include "float.hpp"

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
public:
    Float rzecz;
    Float img;
    Complex(const Float &, const Float &);
    Complex operator+ (Complex &);
    Complex operator- (Complex);
    Complex operator* (Complex);
    Complex operator/ (Complex &);
};

std::ostream& operator<<(std::ostream &os, const Complex &a);

#endif