#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"

template <class TYP, int ROZM>
class UkladRownanLiniowych {
  Macierz<TYP,ROZM> A;
  Wektor<TYP,ROZM> W;

  public:
  UkladRownanLiniowych () {};
  UkladRownanLiniowych (Macierz<TYP,ROZM> _A, Wektor<TYP,ROZM> _W) : A(_A), W(_W) {};
  const Macierz<TYP,ROZM> wstaw_kolumne (int i, Macierz<TYP,ROZM> M, Wektor<TYP,ROZM> W) const;
  const Wektor<TYP,ROZM> Cramer (UkladRownanLiniowych<TYP,ROZM> X) const;
  void blad (UkladRownanLiniowych<TYP,ROZM> X, Wektor<TYP,ROZM> wynik) const;
  const Macierz<TYP,ROZM> & get_A()const;
  const Wektor<TYP,ROZM> & get_W()const;
  void set_A(Macierz<TYP,ROZM> & in);
  void set_W(Wektor<TYP,ROZM> & in);
};
template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZM> &UklRown);
template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZM> &UklRown);

#endif
