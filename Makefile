gpp = g++
gflags = -O3 -std=c++17

kalkulator.exe: bignum.o integer.o float.o funkcje.o complex.o funkcje.o main.o onp.o
	$(gpp) $(gflags) main.o onp.o complex.o funkcje.o float.o integer.o bignum.o -o kalkulator.exe

bignum.o: bignum.hpp bignum.cpp
	$(gpp) $(gflags) bignum.cpp -c -o bignum.o

integer.o: bignum.hpp bignum.cpp integer.hpp integer.cpp
	$(gpp) $(gflags) integer.cpp -c -o integer.o

float.o: bignum.hpp bignum.cpp integer.hpp integer.cpp float.cpp float.hpp
	$(gpp) $(gflags) float.cpp -c -o float.o

funkcje.o: funkcje.hpp funkcje.cpp bignum.hpp bignum.cpp integer.hpp integer.cpp float.cpp float.hpp
	$(gpp) $(gflags) funkcje.cpp -c -o funkcje.o

complex.o: funkcje.hpp funkcje.cpp bignum.hpp bignum.cpp integer.hpp integer.cpp float.cpp float.hpp complex.cpp complex.hpp
	$(gpp) $(gflags) complex.cpp -c -o complex.o

onp.o: funkcje.hpp funkcje.cpp bignum.hpp bignum.cpp integer.hpp integer.cpp float.cpp float.hpp onp.cpp onp.hpp
	$(gpp) $(gflags) onp.cpp -c -o onp.o

main.o: funkcje.hpp funkcje.cpp bignum.hpp bignum.cpp integer.hpp integer.cpp float.cpp float.hpp onp.cpp onp.hpp main.cpp complex.cpp complex.hpp
	$(gpp) $(gflags) main.cpp -c -o main.o
