#include "bignum.hpp"

#ifndef INTEGER_HPP
#define INTEGER_HPP

class Integer
{
public:
    string number;
    bool zn;
    Integer(std::string a = "1", bool sign = 1);
    Integer operator+(const Integer &);
    Integer operator-(Integer);
    Integer operator*(const Integer &);
    Integer operator*(const string &);
    Integer operator/(const Integer &);
    Integer operator%(const Integer &);
    Integer operator^(const Integer &);
    bool operator==(const Integer &);
    bool operator!=(const Integer &);
    bool operator<=(Integer &);
    bool operator>(Integer &);
    bool operator>=(Integer &);
    bool operator<(Integer &);
};

ostream &operator<<(ostream &, const Integer &);

#endif