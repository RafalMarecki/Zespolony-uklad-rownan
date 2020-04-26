#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/rozmiar.h"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include <iostream>



class Macierz {
  Wektor tabM[ROZMIAR];

  public:
  Macierz();
  Macierz(Wektor A, Wektor B, Wektor C); /*konstruktor macierzy*/
  Wektor & operator [] (int i);
  const Wektor & operator [] (int i) const;
  const Macierz transpozycja () const ;
  const Wektor operator * (const Wektor & W2) const; /* Macierz*Wektor */
  const Macierz operator * (Macierz A) const; /* Macierz*Macierz */
  const Macierz operator * (double l) const;
  const Macierz operator / (double l) const;
  const Macierz operator + (const Macierz & A) const;
  const Macierz operator - (const Macierz & A) const;
  bool operator == (const Macierz & A) const;
  bool operator != (const Macierz & A) const;
  const double wyznacznik() const;
  /*const Macierz wstaw_kolumne (int, Macierz, Wektor) const;*/
};

std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);






#endif
