#include "funkcje.hpp"
#include "onp.hpp"
#include <string>

using namespace std;

int main()
{
    string zapytanie;
    int precyzja;
    cin >> precyzja;
    getline(cin, zapytanie);
    cout << obl(onp(zapytanie), precyzja) << '\n';
    return 0;
}
