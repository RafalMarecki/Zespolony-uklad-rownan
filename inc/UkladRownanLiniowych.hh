#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"

class UkladRownanLiniowych {
  Macierz A;
  Wektor W;

  public:
  UkladRownanLiniowych () {};
  UkladRownanLiniowych (Macierz _A, Wektor _W) : A(_A), W(_W) {};
  const Macierz wstaw_kolumne (int i, Macierz M, Wektor W) const;
  const Wektor Cramer (UkladRownanLiniowych X) const;
  void blad (UkladRownanLiniowych X, Wektor wynik) const;
  Macierz & get_A();
  Wektor & get_W();
  void set_A(Macierz & in) const;
  void set_W(Wektor & in) const;
};
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown);

#endif
