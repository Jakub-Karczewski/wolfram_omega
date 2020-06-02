#include "float.hpp"

using namespace std;

void Float::delet()
{
    for (int i = mantyssa.number.size() - 1; i > 0 && mantyssa.number[i] == '0'; i--)
    {
        wyk++;
        mantyssa.number.pop_back();
    }
    long long odz = -wyk - prec;
    for (int i = 0; i < odz && mantyssa.number.size() > 0; i++)
    {
        mantyssa.number.pop_back();
        wyk++;
    }
}

Float::Float(const long long &SS, const string &XX, const long long &xx, const bool &rak)
{
    mantyssa.number = XX;
    wyk = xx;
    mantyssa.zn = rak;
    prec = SS;
    delet();
}

Float Float::operator*(const Float &ans)
{
    Float creative(prec);
    creative.mantyssa = mantyssa * ans.mantyssa;
    creative.wyk = wyk + ans.wyk;
    creative.delet();
    return creative;
}

Float Float::operator+(const Float &odp)
{
    Float creative(prec);
    if (mantyssa.number == "0")
    {
        creative = odp;
        return creative;
    }
    if (odp.mantyssa.number == "0")
    {
        creative = *this;
        return creative;
    }
    if (wyk >= odp.wyk)
    {
        creative.mantyssa = mantyssa;
        for (int i = 0; i < wyk - odp.wyk; i++)
        {
            creative.mantyssa.number += '0';
        }
        creative.wyk = odp.wyk;
        creative.mantyssa = creative.mantyssa + odp.mantyssa;
    }
    else
    {
        creative.mantyssa = odp.mantyssa;
        for (int i = 0; i < odp.wyk - wyk; i++)
        {
            creative.mantyssa.number += '0';
        }
        creative.wyk = wyk;
        creative.mantyssa = creative.mantyssa + mantyssa;
    }
    creative.delet();
    return creative;
}

Float Float::operator-(Float ls)
{
    ls.mantyssa.zn = !ls.mantyssa.zn;
    Float wyn = (*this) + ls;
    ls.mantyssa.zn = !ls.mantyssa.zn;
    return wyn;
}

Float Float::operator/(const Float &space)
{
    Float c(prec, mantyssa.number, wyk);
    c.mantyssa.zn = mantyssa.zn;
    long long liczba = prec + space.mantyssa.number.size() - c.mantyssa.number.size();
    for (int i = 0; i < liczba; i++)
        c.mantyssa.number += '0';
    c.mantyssa = c.mantyssa / space.mantyssa;
    c.wyk = c.wyk - max(0ll, liczba) - space.wyk;
    c.delet();
    return c;
}

bool Float::compare_Float(Float &X)
{
    long long com = mantyssa.number.size() + wyk - X.mantyssa.number.size() - X.wyk;
    if (com > 0)
        return 0;
    else if (com < 0)
        return 1;
    else
    {
        X.delet();
        delet();
        return compare(mantyssa.number, X.mantyssa.number);
    }
}

bool Float::operator==(Float &Y)
{
    delet();
    Y.delet();
    return wyk == Y.wyk && mantyssa == Y.mantyssa;
}

bool Float::operator!=(Float &sat)
{
    return !((*this) == sat);
}
bool Float::operator<=(Float &com)
{
    return (*this) == com || compare_Float(com);
}

bool Float::operator>(Float &com)
{
    return (*this) != com && !compare_Float(com);
}

bool Float::operator>=(Float &com)
{
    return !compare_Float(com);
}

bool Float::operator < (Float &cpp)
{
    return compare_Float(cpp);
}

Float Float::operator~()
{
    Float XD(prec);
    if (wyk >= 0)
    {
        XD.mantyssa = mantyssa;
        for (int i = 0; i < wyk; i++)
        {
            XD.mantyssa.number += '0';
        }
        return XD;
    }
    int il = mantyssa.number.size() + wyk;
    if(il >= 0)
        XD.mantyssa.number = mantyssa.number.substr(0, il);
    else
        XD.mantyssa.number = "0";
    XD.mantyssa.zn = mantyssa.zn;
    XD.wyk = 0;
    if(XD.mantyssa.number == "")
        XD.mantyssa.number = "0";
    return XD;
}

Float Float::operator % ( Float &a)
{
    return (*this)-(a*(~((*this)/a)));
}

ostream &operator<<(ostream &os, const Float &obj)
{
    if (!obj.mantyssa.zn)
        os << '-';
    if (obj.wyk < 0)
    {
        long long point = obj.mantyssa.number.size() + obj.wyk - 1;
        bool dupa = 0;
        if (point <= -1)
        {
            os << "0.";
            dupa = 1;
        }
        for (int i = point; i < -1; i++)
        {
            os << '0';
        }
        if (point <= -1)
        {
            point = -1;
        }
        for (int i = 0; i <= point; i++)
        {
            os << obj.mantyssa.number[i];
        }
        if (!dupa)
        {
            os << '.';
        }
        for (int i = point + 1; i < obj.mantyssa.number.size(); i++)
        {
            os << obj.mantyssa.number[i];
        }
    }
    else
    {
        os << obj.mantyssa.number;
        for (int i = 0; i < obj.wyk; i++)
        {
            os << '0';
        }
    }
    return os;
}