#include "float.hpp"

#ifndef FLOAT_HPP
#define FLOAT_HPP
 
class Complex
{
public:
    Float rzecz;
    Float img;
    Complex(const Float & = jed, const Float & = dwa);
    Complex operator +(Complex &);
    Complex operator -( Complex &);
    Complex operator*(Complex);
    Complex operator/(Complex &);
};

ostream& operator<<(ostream &os, const Complex &a);

#endif