#include "funkcje.hpp"

using namespace std;

Float sqr(const Float &a)
{
    int i = 0;
    Float liczba(a.prec, "1", (a.wyk + a.mantyssa.number.size()) / 2), zwei(a.prec, "2"), liczba(a.prec), Epsilon(a.prec, "1", -(a.prec / 2)), pop(a.prec), roznica(a.prec), zero(a.prec);
    if (!a.mantyssa.zn)
        exit(-1);
    if(a.mantyssa.number == "0")
        return zero;
    liczba = a;
    liczba.wyk = liczba.wyk % 2;
    // long long E = (mantyssa.number.size()+prec+ max(0ll, wyk))/2+2;
    do
    {
        pop = liczba;
        liczba = (liczba + liczba / liczba) / zwei;
        roznica = liczba - pop;
        roznica.mantyssa.zn = 1;
        i++;
    }
    while (roznica > Epsilon && roznica != zero);
    liczba.wyk += a.wyk / 2;
    return liczba;
}

Float arctg(Float X)
{
    Float wyn(X.prec, "1"), iloczyn(X.prec, "1"), dwa(X.prec, "2"), k(X.prec, "1"), Epsi(X.prec, "1", -X.prec + 2), kwadrat(X.prec), multi(X.prec), suma(X.prec, "3");
    kwadrat = X * X;
    multi = kwadrat * dwa;
    do
    {
        iloczyn = iloczyn * multi / (suma * (kwadrat + k));
        wyn = wyn + iloczyn;
        suma = suma + dwa;
        multi = multi + (dwa * kwadrat);
    }
    while (iloczyn > Epsi);
    return wyn * X / (kwadrat + k);
}

Float arcsin(Float value)
{
    Float wyn(value.prec, "0"), multi(value.prec, "0"), wartosc(value.prec, "1"), last(value.prec, "0"), wartosc_2(value.prec, "1"), Epsi(value.prec, "1", -value.prec + 3), pref(value.prec);
    Float last_2(value.prec, "0"), border(value.prec, "11"), ink(value.prec, "1"), pot_2(value.prec, "1"), dwa(value.prec, "2"), pop(value.prec), suma(value.prec, "1");
    wyn = value;
    pop = value;
    do
    {
        last = last + ink;
        last_2 = last_2 + dwa;
        wartosc = wartosc * last;
        pop = pop * value * value;
        suma = suma + dwa;
        pot_2 = pot_2 * dwa;
        wartosc_2 = wartosc_2 * (last_2 - ink) * (last_2);
        pref = (wartosc_2 * pop) / (pot_2 * pot_2 * wartosc * wartosc * suma);
        wyn = wyn + pref;
        cout << wartosc_2 << '\n' << (pot_2 * pot_2 * wartosc * wartosc) << '\n' << pop << '\n' << suma << '\n' << '\n';
    }
    while(pref > Epsi);
    return wyn;
}

Float arcsin_2(Float value)
{
    Float dwa(value.prec, "2"), jeden(value.prec, "1");
    //cout << value/(jeden + sqr(jeden - (value * value))) << '\n';
    return dwa * arctg(value/(jeden + sqr(jeden - (value * value))));
}

Float arccos(Float value)
{
    Float dwa(value.prec, "2"), jeden(value.prec, "1");
    return dwa * arctg(sqr(jeden - (value * value))/(jeden+value));
}

Float Ramurajan(long long &pre)
{
    long long pop = pre;
    pre += 10;
    Float czysta(pre, "396"), silnia(pre, "24"), silnia_1(pre, "1"), suma(pre, "27493"), iloczyn(pre), wyn(pre, "1103"), k(pre, "1"), z(pre, "4"), ink(pre, "1");
    Float dwa(pre, "2"), trzy(pre, "3"), cztery(pre, "4"), square(pre, "2"), dod(pre, "26390"), dzi(pre, "9801"), dupa(pre, "2");
    long long ile = pop / 8;
    dupa = dwa * sqr(dupa);
    czysta = czysta * czysta;
    czysta = czysta * czysta;
    iloczyn = czysta;
    for (long long i = 0; i < ile; i++)
    {
        wyn = wyn + (silnia * suma) / (silnia_1 * iloczyn);
        silnia = silnia * (z + ink) * (z + dwa) * (z + trzy);
        z = z + cztery;
        silnia = silnia * z;
        k = k + ink;
        square = k * k;
        square = square * square;
        silnia_1 = silnia_1 * square;
        suma = suma + dod;
        iloczyn = iloczyn * czysta;
        // cout << iloczyn << '\n';
    }
    return dzi / (dupa * wyn);
}

Float sin(Float &sg)
{
    bool X = 0;
    Float pot(sg.prec), silnia(sg.prec, "1"), k(sg.prec), jed(sg.prec, "1"), dwa(sg.prec, "2"), wynik(sg.prec, "0"), kw(sg.prec), sl(sg.prec);
    Float il(sg.prec), Epsilon(sg.prec + 2, "1", -sg.prec + 1), p(sg.prec, "6283", -3);
    //if(sg > p)
    //sg = sg%(dwa*Pi);
    k = sg;
    kw = k * k;
    pot = sg;
    sl = jed;
    do
    {
        il = pot / silnia;
        if (X)
            wynik = wynik - il;
        else
            wynik = wynik + il;
        X = !X;
        silnia = silnia * (sl + jed);
        sl = sl + dwa;
        silnia = silnia * sl;
        pot = pot * kw;
    }
    while (il > Epsilon);
    return wynik;
}

Float cos(Float &arg)
{
    Float pot(arg.prec), sil(arg.prec, "2"), jed(arg.prec, "1"), dwa(arg.prec, "2"), k(arg.prec, "2"), Epsi(arg.prec + 2, "1", -arg.prec + 1), wynik(arg.prec, "1");
    Float iloraz(arg.prec), sq(arg.prec);
    bool add = 0;
    pot = arg * arg;
    sq = pot;
    do
    {
        iloraz = pot / sil;
        if (add)
            wynik = wynik + iloraz;
        else
            wynik = wynik - iloraz;
        add = !add;
        sil = sil * (k + jed);
        k = k + dwa;
        sil = sil * k;
        pot = pot * sq;
    }
    while (iloraz > Epsi);
    return wynik;
}

Float Fi(const long long &h)
{
    Float piec(h, "5"), jed(h, "1"), dwa(h, "2");
    return (jed + sqr(piec)) / dwa;
}

Float Euler(Float x)
{
    Float ink(x.prec, "1"), silnia(x.prec, "2"), pot(x.prec, "1"), wyn(x.prec, "0"), ost(x.prec, "2"), Eps(x.prec, "1", -x.prec + 1), wart(x.prec);
    wyn = x + ink;
    pot = x * x;
    do
    {
        wart = pot / silnia;
        wyn = wyn + wart;
        pot = pot * x;
        ost = ost + ink;
        silnia = silnia * ost;
    }
    while (wart > Eps);
    wyn = wyn + Eps;
    return wyn;
}

Float ln(Float num)
{
    bool mor = true;
    Float n(num.prec, "1"), pot(num.prec, "1"), res(num.prec, "0"), ink(num.prec, "1"), dwoja(num.prec, "2"), il(num.prec, "0"), jednadruga(num.prec, "5", -1), zero(num.prec, "0"), wart(num.prec), Eps(num.prec, "1", -num.prec + 1);
    while (num >= ink)
    {
        num = (num / dwoja);
        il = il + ink;
    }
    while (num < jednadruga)
    {
        num = num * dwoja;
        il = il - ink;
    }

    num = num - ink;
    do
    {
        pot = pot * num;
        wart = pot / n;
        if (mor)
            res = res + wart;
        else
            res = res - wart;
        mor = !mor;
        n = n + ink;
        wart.mantyssa.zn = 1;
    }
    while (wart > Eps);
    res = res+Eps;
    if (il != zero)
        res = res - (il * ln(jednadruga));

    return res;
}

Float pot(Float a, Float w) // zwraca a^w
{
    return Euler(ln(a) * w);
}

Float log(Float a, Float b)
{
    return ln(b) / ln(a);
}

Float zaokr(Float x, long long il)
{
    if(x.wyk >= 0 || il > -x.wyk)
        return x;
    long long poz = x.mantyssa.number.size() + x.wyk + il;
    x.wyk += x.mantyssa.number.size() - poz;
    if(x.mantyssa.number[poz] > '4')
    {
        Float jedynka(x.prec, "1", -il);
        x.mantyssa.number = x.mantyssa.number.substr(0, poz);
        return x + jedynka;
    }
    x.mantyssa.number = x.mantyssa.number.substr(0, poz);
    return x;
}


Float Ceil(Float x)
{
     if(x.wyk >= 0)
        return x;
     if(!x.mantyssa.zn)
        return (~x);
     else
        return (~x) + jed;
}

Float Floor(Float x)
{
    Float jed(x.prec, "1");
    if(x.wyk >= 0)
        return x;
    if(x.mantyssa.zn)
        return (~x);
    else
        return (~x) - jed;
}

Float Float::operator ^(Float bignum)
{
    Float jeden(prec, "1"), wyn(prec);
    if(bignum.mantyssa.number == "0")
        return jeden;
    if(bignum.mantyssa.zn == 0)
    {
        if(mantyssa.number == "0")
        {
            cerr << "0 DIVISION ERROR\n";
            exit(-1);
        }
        bignum.mantyssa.zn = 1;
        return jeden/((*this) ^ bignum);
    }
    Float calk;
    string dz = "10";
    calk = (~bignum);
    bignum = bignum - calk;
    wyn.mantyssa.number = fast_power(mantyssa.number, stoll(calk.mantyssa.number));
    wyn.wyk = wyk * stoll(calk.mantyssa.number) * stoll(fast_power(dz, calk.wyk)); // jeszcze 10^x
    return wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}urn wyn * pot((*this), bignum);
}