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
    Float(const long long & = 51, const std::string & = "0", const long long & = 0, const bool & = 1);
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

std::ostream &operator<<(std::ostream &os, const Float &obj);

#endif