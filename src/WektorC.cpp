#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/src/Wektor.cpp"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"

template class Wektor <double, 5>;
template std::istream & operator>>(std::istream &strm, Wektor<double,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,5> &W);

template class Wektor <LZespolona, 5>;
template std::istream & operator>>(std::istream &strm, Wektor<LZespolona,5> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<LZespolona,5> &W);

template class Wektor <double, 3>;
template std::istream & operator>>(std::istream &strm, Wektor<double,3> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,3> &W);

template class Wektor <LZespolona, 3>;
template std::istream & operator>>(std::istream &strm, Wektor<LZespolona,3> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<LZespolona,3> &W);



