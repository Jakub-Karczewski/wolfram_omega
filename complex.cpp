#include "complex.hpp"

using namespace std;

Float jed_1(100, "1", 0), dwa_2(100, "1", 0);

Complex::Complex(const Float &a = jed_1, const Float &b = dwa_2)
{
    rzecz = a;
    img = b;
}

Complex Complex::operator+ (Complex &a)
{
    Complex ans;
    ans.rzecz = rzecz + a.rzecz;
    ans.img = img + a.img;
    return ans;
}

Complex Complex::operator -(Complex a)
{
    Complex ans;
    ans.rzecz = rzecz - a.rzecz;
    ans.img = img - a.img;
    return ans;
}

Complex Complex::operator*(Complex a)
{
    Complex ans;
    ans.img = (rzecz * a.img) + (a.rzecz * img);
    ans.rzecz = (rzecz * a.rzecz) - (img * a.img);
    return ans;
}

Complex Complex::operator/(Complex &a)
{
    Complex ans;
    Float JD = (a.rzecz * a.rzecz) + (a.img * a.img);
    ans.rzecz = ((rzecz * a.rzecz) + (img * a.img))/JD;
    ans.img = ((img * a.rzecz) - (rzecz * a.img))/JD;
    return ans;
}

ostream& operator<<(ostream &os, const Complex &a)
{
    os << a.rzecz << ' ';
    if(a.img.mantyssa.zn)
        os << "+";
    else
        os << '-';
    os << ' ' << a.img;
    return os;
}