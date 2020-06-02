#include "integer.hpp"

#ifndef FLOAT_HPP
#define FLOAT_HPP

class Float
{
public:
    Integer mantyssa;
    long long wyk;
    long long prec;
    void delet();
    Float(const long long &SS = 51, const string &XX = "0", const long long &xx = 0, const bool &rak = 1);
    Float operator*(const Float &);
    Float operator+(const Float &);
    Float operator-(Float);
    Float operator/(const Float &);
    bool compare_Float(Float &);
    bool operator==(Float &);
    bool operator!=(Float &);
    bool operator<=(Float &);
    bool operator>(Float &);
    bool operator>=(Float &);
    bool operator < (Float &);
    Float operator~();
    Float operator ^(Float);
    Float operator % ( Float &);
};

ostream &operator<<(ostream &os, const Float &obj);

Float jed(100, "1", 0), dwa(100, "1", 0);

#endif