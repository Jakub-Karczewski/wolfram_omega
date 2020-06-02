#include "funkcje.hpp"
#include "onp.hpp"
#include <string>

using namespace std;

int main()
{
    string zapytanie;
    int precyzja;
    cin >> precyzja;
    cin.ignore(1);
    getline(cin, zapytanie);
    cout << OBL(ONP(zapytanie), precyzja) << '\n';
    return 0;
}
