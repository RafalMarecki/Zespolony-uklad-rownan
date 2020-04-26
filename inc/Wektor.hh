#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include "LZespolona.hh"
#include <iostream>

template <class TYP, int ROZM>
class Wektor {
  TYP tabW[ROZM];

  public:
  TYP & operator [] (int i); 
  const TYP & operator[](int i) const;
  Wektor ();
  Wektor (TYP ,TYP ,TYP);
  void wpisz();
  void wypisz();
  const Wektor <TYP,ROZM> operator + (const Wektor <TYP, ROZM> & W2) const;
  const Wektor <TYP,ROZM> operator - (const Wektor <TYP, ROZM> & W2) const;
  const TYP operator * (const Wektor <TYP, ROZM> & W2) const; /* Iloczyn skalarny */
  const Wektor <TYP,ROZM> operator * (TYP l) const; /* Wektor * liczba */ /*const x2*/
  const Wektor <TYP,ROZM> operator / (TYP l) const; /* Wektor / liczba */ /*const x2*/
  bool operator == (const Wektor <TYP, ROZM> & W2) const;
  bool operator != (const Wektor <TYP, ROZM> & W2) const;
  //const TYP dlugosc () const;
};
template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, Wektor <TYP, ROZM> &Wek);
template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const Wektor <TYP, ROZM> &Wek);

  
#endif
