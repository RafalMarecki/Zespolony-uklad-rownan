#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/src/Macierz.cpp"

template class Macierz <double, 5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 5> &Mac);

template class Macierz <LZespolona, 5>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona, 5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona, 5> &Mac);

template class Macierz <double, 3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 3> &Mac);

template class Macierz <LZespolona, 3>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona, 3> &Mac);