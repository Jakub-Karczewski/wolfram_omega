#include "integer.hpp"

using namespace std;

Integer::Integer(string a, bool sign)
{
    number = a;
    zn = sign;
}

Integer Integer::operator+(const Integer &XD)
{
    Integer num;
    num.zn = 1;
    if (zn && XD.zn)
        num.number = addition(number, XD.number);
    else if (!zn && XD.zn)
        num.number = substraction(XD.number, number);
    else if (zn && !XD.zn)
        num.number = substraction(number, XD.number);
    else
    {
        num.number = addition(XD.number, number);
        num.zn = 0;
    }
    if (num.number.back() == '-')
    {
        num.zn = !num.zn;
        num.number.pop_back();
    }
    return num;
}

Integer Integer::operator-(Integer XD)
{
    Integer result;
    XD.zn = !XD.zn;
    result = (*this) + XD;
    XD.zn = !XD.zn;
    return result;
}

Integer Integer::operator*(const Integer &XD)
{
    Integer score;
    score.zn = !(zn ^ XD.zn);
    score.number = Caracuba(number, XD.number);
    return score;
}

Integer Integer::operator*(const string &paper)
{
    Integer wynik;
    wynik.zn = zn;
    if (paper.back() == '-')
        wynik.zn = !wynik.zn;
    wynik.number = multiplication(number, paper);
    return wynik;
}

Integer Integer::operator/(const Integer &XD)
{
    Integer wyn;
    wyn.zn = !(zn ^ XD.zn);
    wyn.number = dziel(number, XD.number).first;
    return wyn;
}

Integer Integer::operator%(const Integer &XD)
{
    Integer wyn;
    wyn.zn = 1;
    wyn.number = dziel(number, XD.number).second;
    return wyn;
}

Integer Integer::operator^(const Integer &XD)
{
    Integer pot;
    pot.zn = 1;
    if (!XD.zn && number != "1")
        pot.number = "0";
    else
    {
        if (!zn && (XD.number.back() - '0') & 1)
            pot.zn = 0;
        pot.number = fast_power(number, stoi(XD.number));
    }
    return pot;
}

bool Integer::operator==(const Integer &XXX)
{
    return number == XXX.number && zn == XXX.zn;
}

bool Integer::operator!=(const Integer &XXX)
{
    return !((*this) == XXX);
}

bool Integer::operator<=(Integer &XXX)
{
    return (*this) == XXX || !(((*this) - XXX).zn);
}

bool Integer::operator>(Integer &XXX)
{
    return (*this) != XXX && ((*this) - XXX).zn;
}

bool Integer::operator>=(Integer &XXX)
{
    return (*this) == XXX || ((*this) - XXX).zn;
}

bool Integer::operator<(Integer &XXX)
{
    return (*this) != XXX && !(((*this) - XXX).zn);
}

ostream &operator<<(ostream &os, const Integer &obj)
{
    if (!obj.zn)
        os << '-';
    os << obj.number;
    return os;
}
