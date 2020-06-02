#include <iostream>
#include <string>
#include <ctime>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <set>
#include <vector>

#ifndef BIGNUM_HPP
#define BIGNUM_HPP

bool con = 0;
bool compare(const std::string &, const std::string &);

std::string zero(const int &);

void usuwanko(std::string &);

std::string substraction(const std::string &, const std::string &);

std::pair<char, bool> dod_liter(const char &, const char &, bool &);

std::string addition(const std::string &a, const std::string &);

std::pair<char, short> mnoz_liter(const char &, const char &, const short &);

std::string multiplication(const std::string &, const std::string &);

std::string Sub_dziel(std::string , const std::string &, bool);

bool compare_do_dziel(const std::string &, const std::string &, const int &);

std::pair<std::string, std::string> dziel(std::string , const std::string &);

std::string Caracuba(const std::string &, const std::string &);

std::string fast_power(const std::string &, long long );

std::string Factorial(std::string);

std::string euklides(const std::string &, const std::string &);

std::string NWW(const std::string &, const std::string &);

#endif