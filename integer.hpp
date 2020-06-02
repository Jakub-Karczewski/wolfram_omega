#include "bignum.hpp"

#ifndef INTEGER_HPP
#define INTEGER_HPP

class Integer
{
public:
    std::string number;
    bool zn;
    Integer(std::string = "1", bool = 1);
    Integer operator+(const Integer &);
    Integer operator-(Integer);
    Integer operator*(const Integer &);
    Integer operator*(const std::string &);
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

std::ostream &operator<<(std::ostream &, const Integer &);

#endif