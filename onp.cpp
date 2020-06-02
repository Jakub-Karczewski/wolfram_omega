#include "onp.hpp"

using namespace std;

int pior(const char &z)
{
    if(z == '(')
        return 0;
    if(z == '+' || z == '-')
        return 1;
    if(z == '*' || z == '/' || z == '%')
        return 2;
    if(z == '^')
        return 3;
    if(z == 's' || z == 'c' || z == 'S' || z == 'C' || z == 't' || z == 'T' || z == 'l' || z == 'e' || z == 'q' ||  z == 'f' || z == 'i' || z == 'n' || z == 'r' || z == 'F')
        return 4;
    if(z == ',')
        return -2;
    if(z == ')')
        return -3;
    return -1;
}

bool czy(const char &a)
{
    set<char> operand = {'s', 'c', 'a','t', 'l', 'e', 'f', 'r'};
    return operand.find(a) != operand.end();
}

bool dz(const char &a)
{
    set<char> dzi = {'s', 'S', 'c','C', 't', 'T', 'e', 'n', 'q', 'f', 'i', 'F'};
    return dzi.find(a) != dzi.end();
}

string ONP(string inp)
{
    stack <char> stos;
    vector <string> tokeny;
    string licz, op, dupsko, wyk;
    bool kropka = 0;
    int wykl = 0, i = 0;
    while(i < inp.size())
    {

        if(inp[i] <= '9' && inp[i] >= '0')
        {
            licz += inp[i];
            if(kropka)
                wykl--;
        }
        else if(inp[i] == '.')
            kropka = 1;
        else if(czy(inp[i]))
        {
            if(inp[i] == 's' && inp.size() - i > 3 && inp[i+1] == 'i' && inp[i+2] == 'n')
            {
                tokeny.push_back("s");
                i += 2;
            }
            else if(inp[i] == 'c' && inp.size() - i > 3 && inp[i+1] == 'o' && inp[i+2] == 's')
            {
                tokeny.push_back("c");
                i += 2;
            }
            else if(inp[i] == 't' && inp.size() - i > 3 && inp[i+1] == 'a' && inp[i+2] == 'n')
            {
                tokeny.push_back("t");
                i += 2;
            }
            else if(inp[i] == 'l' && inp.size() - i > 3 && inp[i+1] == 'o' && inp[i+2] == 'g')
            {
                tokeny.push_back("l");
                i += 2;
            }
            else if(inp[i] == 'l' && inp.size() - i > 2 && inp[i+1] == 'n')
            {
                tokeny.push_back("n");
                i++;
            }
            else if(inp[i] == 'e' && inp.size() - i > 3 && inp[i+1] == 'x' && inp[i+2] == 'p')
            {
                tokeny.push_back("e");
                i += 2;
            }
            else if(inp[i] == 's' && inp.size() - i > 4 && inp[i+1] == 'q' && inp[i+2] == 'r' && inp[i+3] == 't')
            {
                tokeny.push_back("q");
                i += 3;
            }
            else if(inp[i] == 'r' && inp.size() - i > 5 && inp[i+1] == 'o' && inp[i+2] == 'u' && inp[i+3] == 'n' && inp[i+4] == 'd')
            {
                tokeny.push_back("r");
                i += 4;
            }
            else if(inp[i] == 'f' && inp.size() - i > 5 && inp[i+1] == 'l' && inp[i+2] == 'o' && inp[i+3] == 'o' && inp[i+4] == 'r')
            {
                tokeny.push_back("f");
                i += 4;
            }
            else if(inp[i] == 'c' && inp.size() - i > 4 && inp[i+1] == 'e' && inp[i+2] == 'i' && inp[i+3] == 'l')
            {
                tokeny.push_back("i");
                i += 3;
            }
            else if(inp[i] == 'f' && inp.size() - i > 4 && inp[i+1] == 'a' && inp[i+2] == 'c' && inp[i+3] == 't')
            {
                tokeny.push_back("F");
                i += 4;
            }
            else if(inp[i] == 'a' && inp.size() - i > 6 && inp[i+1] == 'r' && inp[i+2] == 'c')
            {
                if(inp[i+3] == 'c' && inp[i+4] == 'o' && inp[i+5] == 's')
                {
                    tokeny.push_back("C");
                    i += 5;
                }
                else if(inp[i+3] == 's'  && inp[i+4] == 'i' && inp[i+5] == 'n')
                {
                    tokeny.push_back("S");
                    i += 5;
                }
                else if(inp[i+3] == 't'  && inp[i+4] == 'a' && inp[i+5] == 'n')
                {
                    tokeny.push_back("T");
                    i += 5;
                }
                else
                {
                    cerr << "NIEPRAWIDLOWE DANE";
                    exit(0);
                }

            }
            else
            {
                cerr << "NIEPRAWIDLOWE DANE";
                exit(0);
            }
        }
        else
        {
            if(licz != "")
                tokeny.push_back(licz + ";" + to_string(wykl));
            if(inp[i] != ' ' && inp[i] != '=')
            {
                op = inp[i];
                tokeny.push_back(op);
            }
            licz = "";
            wykl = 0;
            kropka = 0;
        }
        i++;
    }
    if(licz != "")
        tokeny.push_back(licz + ";" + to_string(wykl));
    //for(const string &ss : tokeny)
    //cout << ss << ' ';
    for(int i = 0; i < tokeny.size(); i++)
    {
        int p = pior(tokeny[i][0]);
        if(p <= -2)
        {
            while(stos.size() > 0)
            {
                if(stos.top() != '(')
                {
                    dupsko += stos.top();
                    dupsko += ' ';
                    stos.pop();
                }
                else
                {
                    if(p == -3)
                        stos.pop();
                    break;
                }
            }
        }
        else if(tokeny[i][0] == '(')
            stos.push('(');
        else if(p > 0)
        {
            while(stos.size() > 0)
            {
                if(pior(stos.top()) >= p)
                {
                    dupsko += stos.top();
                    dupsko += ' ';
                    stos.pop();
                }
                else
                    break;
            }
            stos.push(tokeny[i][0]);
        }
        else
            dupsko += tokeny[i]+" ";
    }
    while(stos.size() > 0)
    {
        dupsko += stos.top();
        dupsko += ' ';
        stos.pop();
    }
    return dupsko;
}

Float OBL(string inp, int prec)
{
    stack <Float> stos;
    vector <string> tokeny;
    string licz, op;
    for(int i = 0; i < inp.size(); i++)
    {
        if(inp[i] == ';' || inp[i] == '-' || (inp[i] <= '9' && inp[i] >= '0'))
            licz += inp[i];
        else
        {
            if(licz != "")
                tokeny.push_back(licz);
            if(inp[i] != ' ' && inp[i] != '=')
            {
                op = inp[i];
                tokeny.push_back(op);
            }
            licz = "";
        }
    }
    if(licz != "")
        tokeny.push_back(licz);
    for(int i = 0; i < tokeny.size(); i++)
    {
        if(tokeny[i][0] <= '9' && tokeny[i][0] >= '0')
        {
            Float a(prec);
            int wyk = 0;
            string mantyssa;
            bool found = 0;
            for(int j = tokeny[i].size()-1, c = 0; j > -1 && c < 9; j--, c++)
            {
                if(tokeny[i][j] == ';')
                {
                    mantyssa = tokeny[i].substr(0, j);
                    wyk = stoi(tokeny[i].substr(j+1));
                    usuwanko(mantyssa);
                    a.mantyssa.number = mantyssa;
                    a.wyk = wyk;
                    found = 1;
                    break;
                }
            }
            if(!found)
                a.mantyssa.number = tokeny[i];
            stos.push(a);
        }
        else
        {
            if(stos.empty())
            {
                cerr << "NIE LAM TWIERDZEN MATEMATYCZNYCH";
                exit(0);
            }
            Float a(prec);
            Float b(prec);
            b = stos.top();
            stos.pop();
            if(!dz(tokeny[i][0]))
            {
                a = stos.top();
                stos.pop();
            }
            switch(tokeny[i][0])
            {
            case '+':
                stos.push(a + b);
                break;
            case '-':
                stos.push(a - b);
                break;
            case '*':
                stos.push(a * b);
                break;
            case '%':
                if(b.mantyssa.number == "0")
                {
                    cerr << "NIE LAM TWIERDZEN MATEMATYCZNYCH";
                    exit(0);
                }
                stos.push(a % b);
                break;
            case '/':
                if(b.mantyssa.number == "0")
                {
                    cerr << "NIE LAM TWIERDZEN MATEMATYCZNYCH";
                    exit(0);
                }
                stos.push(a / b);
                break;
            case 'l':
                stos.push(log(a, b));
                break;
            case '^':
                stos.push(a ^ b);
                break;
            case 's':
                stos.push(sin(b));
                break;
            case 'c':
                stos.push(cos(b));
                break;
            case 'T':
                stos.push(arctg(b));
                break;
            case 'S':
                stos.push(arcsin_2(b));
                break;
            case 'C':
                stos.push(arccos(b));
                break;
            case 't':
                stos.push(sin(b)/cos(b));
                break;
            case 'n':
                stos.push(ln(b));
                break;
            case 'e':
                stos.push(Euler(b));
                break;
            case 'q':
                stos.push(sqr(b));
                break;
            case 'i':
                stos.push(Ceil(b));
                break;
            case 'f':
                stos.push(Floor(b));
                break;
            case 'r':
            {
                long long arg = 0;
                for(long long i = 0; i < b.wyk; i++)
                    b.mantyssa.number += '0';
                arg = stoll(b.mantyssa.number);
                if(b.mantyssa.zn)
                    stos.push(zaokr(a, arg));
                else
                {
                    cerr << "NIE LAM TWIERDZEN MATEMATYCZNYCH";
                    exit(0);
                }

                break;
            }
            case 'F':
                if(b.mantyssa.number == "0" || (b.wyk >= 0 && b.mantyssa.zn))
                {
                    b.mantyssa.number = Factorial(b.mantyssa.number);
                    stos.push(b);
                }
                else
                {
                    cerr << "NIE LAM TWIERDZEN MATEMATYCZNYCH";
                    exit(0);
                }
                break;
            }
        }
    }
    if(stos.size() != 1)
    {
        cerr << "BLAD: zla ilosc operatorow lub liczb\n";
        exit(-1);
    }
    return stos.top();
}