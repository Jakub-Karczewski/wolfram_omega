#include "bignum.hpp"

using namespace std;
bool con = 0;
bool compare(const string &a, const string &b)
{
    if (b.size() > a.size())
        return 1;
    if (b.size() < a.size())
        return 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            return 0;
        else if (a[i] < b[i])
            return 1;
    }
    return 0;
}

string zero(const int &lp)
{
    string dupsko;
    for (int i = 0; i < lp; i++)
        dupsko += '0';
    return dupsko;
}

void usuwanko(string &letter)
{
    int del = -1;
    for (int i = 0; letter[i] == '0' && i < letter.size() - 1; i++)
        del = i;
    if (del > -1)
        letter = letter.substr(del + 1);
}

string substraction(const string &a, const string &b)
{
    bool carry = 0;
    string c;
    if (compare(a, b))
    {
        con = 1;
        return substraction(b, a);
    }
    for (int i = a.size() - 1, j = b.size() - 1; j > -1; j--, i--)
    {
        if (a[i] < b[j] + carry)
        {
            c += a[i] - b[j] - carry + 58;
            carry = 1;
        }
        else
        {
            c += a[i] - b[j] + '0' - carry;
            carry = 0;
        }
    }
    for (int i = a.size() - b.size() - 1; i > -1; i--)
    {
        if (carry)
        {
            if (a[i] == '0')
                c += '9';
            else
            {
                c += a[i] - 1;
                carry = 0;
            }
        }
        else
            c += a[i];
    }
    reverse(c.begin(), c.end());
    usuwanko(c);
    if (con)
        c += '-';
    con = 0;
    return c;
}
pair<char, bool> dod_liter(const char &a, const char &b, bool &yhm)
{
    char d = a + b - '0' + yhm;
    yhm = 0;
    if (d > '9')
    {
        d -= 10;
        yhm = 1;
    }
    return make_pair(d, yhm);
}

string addition(const string &a, const string &b)
{
    pair<char, bool> wyn;
    bool add = 0;
    string c;
    if (compare(a, b))
        return addition(b, a);
    for (int i = a.size() - 1, j = b.size() - 1; j > -1; j--, i--)
    {
        wyn = dod_liter(a[i], b[j], add);
        c += wyn.first;
        add = wyn.second;
    }

    for (int i = a.size() - b.size() - 1; i > -1; i--)
    {
        if (add)
        {

            if (a[i] == '9')
                c += '0';
            else
            {
                c += a[i] + 1;
                add = 0;
            }
        }
        else
            c += a[i];
    }
    if (add)
        c += '1';
    reverse(c.begin(), c.end());
    usuwanko(c);
    return c;
}
pair<char, short> mnoz_liter(const char &a, const char &b, const short &mel)
{
    short add = 0, wyn = (a - '0') * (b - '0') + mel;
    if (wyn > 9)
    {
        add = wyn / 10;
        wyn %= 10;
    }
    return make_pair(char(wyn + '0'), add);
}

string multiplication(const string &a, const string &b)
{
    short wyn, add = 0;
    int ilezer = 0, ilezer_1 = 0, roz = 0;
    string c, d = "0", g;
    pair<char, short> flam, les;
    char sur;
    if (a[0] == '0' || b[0] == '0')
    {
        return "0";
    }
    for (int i = a.size() - 1; a[i] == '0' && i > 0; i--)
        ilezer++;
    for (int i = b.size() - 1; b[i] == '0' && i > 0; i--)
        ilezer_1++;
    for (int i = a.size() - 1 - ilezer; i > -1; i--)
    {
        if (a[i] == '0')
        {
            g += '0';
            continue;
        }
        add = 0;
        for (int j = b.size() - 1 - ilezer_1; j > -1; j--)
        {
            flam = mnoz_liter(b[j], a[i], add);
            add = flam.second;
            c += flam.first;
        }
        if (add > 0)
            c += char(add + '0');
        reverse(c.begin(), c.end());
        d = addition(d, c + g);
        c.clear();
        g += '0';
    }
    for (int i = 0; i < ilezer + ilezer_1; i++)
        d += '0';
    return d;
}

string Sub_dziel(string a, const string &b, bool cyk)
{
    bool carry = 0;
    for (int i = b.size()-1; i >= 0; i--)
    {
        if (a[i+cyk] >= b[i] + carry)
        {
            a[i+cyk] -= b[i] + carry - '0';
            carry = 0;
        }
        else
        {
            a[i+cyk] -= b[i] + carry - 58;
            carry = 1;
        }
    }
    if (carry)
        a[0]--;
    usuwanko(a);
    return a;
}

bool compare_do_dziel(const string &a, const string &b, const int &zera)
{
    if (a.size() > b.size() + zera)
        return 0;
    if (a.size() < b.size() + zera)
        return 1;
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] > b[i])
            return 0;
        if (a[i] < b[i])
            return 1;
    }
    int what = a.size() - b.size();
    for (int i = what; i < a.size(); i++)
    {
        if (a[i] != '0')
            return 0;
    }
    return 0;
}

pair<string, string> dziel(string a, const string &b)
{
    int zer = 0, i = -1, liczba = a.size() - b.size();
    int ile;
    string iloraz, pom;
    if (b == "0")
        return make_pair("Zero division error ", "Kill yourself");
    if (a == b)
        return make_pair("1", "0");
    if (compare(a, b))
        return make_pair("0", a);
    for (int i = 0; i < liczba; i++)
    {
        iloraz += '0';
        zer++;
    }
    if (!(compare_do_dziel(a, b, zer)))
    {
        iloraz += '0';
        zer++;
    }
    while (zer > -1)
    {
        if (!compare_do_dziel(a, b, zer))
        {
            if(a.size() == b.size()+zer)
                ile = a[0]/b[0];
            else
                ile = (10*(a[0]-'0')+a[1]-'0')/b[0];
            if(ile > 1)
            {
                pom = multiplication(b, to_string(ile));
                a = Sub_dziel(a, pom, (a.size() > pom.size()+zer));
                iloraz[i] += ile;
            }
            else
            {
                a = Sub_dziel(a, b, (a.size() > b.size()+zer));
                iloraz[i]++;
            }
        }
        else
        {
            zer--;
            i++;
        }

    }
    return make_pair(iloraz, a);
}

string Caracuba(const string &a, const string &b)

{
    string c, d, e, f, T_1, T_2, wyni, bonus, sum_1, sum_2, sum_3, multi;
    int N = 0;
    bool minuse = 0;
    if (b.size() == 0 || a.size() == 0 || a[0] == '0' || b[0] == '0')
        return "0";
    if (b.size() > a.size())
        return Caracuba(b, a);
    if (a.size() + b.size() < 17)
        return to_string(stoll(a) * stoll(b));
    if (a.size() < 10)
        return multiplication(a, b);
    N = a.size();
    if (a.size() > b.size())
    {
        if (N & 1)
        {
            N++;
            minuse = 1;
        }
        c = a.substr(0, N / 2 - minuse);
        d = a.substr(N / 2 - minuse);
        if (b.size() <= N / 2)
        {
            e = "0";
            f = b;
        }
        else
        {
            e = b.substr(0, b.size() - N / 2);
            f = b.substr(b.size() - N / 2);
        }
    }
    else
    {
        if (N & 1)
        {
            N++;
            minuse = 1;
        }
        c = a.substr(0, N / 2 - minuse);
        d = a.substr(N / 2 - minuse);
        e = b.substr(0, N / 2 - minuse);
        f = b.substr(N / 2 - minuse);
    }
    bonus = zero(N / 2);
    usuwanko(d);
    usuwanko(f);
    sum_1 = addition(c, d);
    sum_2 = addition(e, f);
    T_1 = Caracuba(c, e);
    T_2 = Caracuba(d, f);
    multi = Caracuba(sum_1, sum_2);
    sum_3 = substraction(multi, T_1);
    sum_3 = substraction(sum_3, T_2);
    wyni = addition(addition(T_1 + bonus + bonus, sum_3 + bonus), T_2);
    return wyni;
}

string fast_power(const string &a, long long b)
{
    string k = "1";
    if (b == 0ll)
    {
        return "1";
    }
    k = fast_power(a, b / 2);
    k = Caracuba(k, k);
    if (b & 1)
    {
        k = Caracuba(k, a);
    }
    return k;
}

string Factorial(string a)
{
    string sz = "20", jed = "1", ans;
    long long pulap = 20, wyn = 1;
    bool jd = 0;
    if(a == sz || compare(a, sz))
    {
        pulap = stoll(a);
        jd = 1;
    }
    for(long long i = 2; i <= pulap; i++)
        wyn *= i;
    ans = to_string(wyn);
    if(!jd)
    {
        sz = "21";
        a = addition(a, jed);
        while(sz != a)
        {
            ans = multiplication(ans, sz);
            sz = addition(sz, jed);
        }

    }
    return ans;
}
string euklides(const string &a, const string &b)
{
    if (b[0] == '0')
        return a;
    return euklides(b, dziel(a, b).second);
}

string NWW(const string &a, const string &b)
{
    return dziel(Caracuba(a, b), euklides(a, b)).first;
}