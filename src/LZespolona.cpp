#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"
#include <iostream>
#include <cstdio>
#include <climits>
#include <math.h>
#include <cmath>
#include <string>
using namespace std;

LZespolona::LZespolona ()
{
  re=0.0; im=0.0;
}

LZespolona::LZespolona (double i, double r)
{
  re=r; im=i;
}

LZespolona & LZespolona::operator = (double i)
{
  this->re=i; this->im=0.0;
  return *this;
}

LZespolona Sprzezenie (LZespolona lz)
{
  lz.im = -lz.im;
  return lz;
}
/*!
 * Realizuje Sprzezenie liczy zespolonej.
 * Argumenty:
 *    lz - liczba, ktorej sprzezenie chcemy uzyskac,
 *   
 * Zwraca:
 *    Sprzezona liczbe zespolona.
 */

double Modul2 (LZespolona lz)
{
  double Wynik;
  Wynik = sqrt(pow(lz.re,2) + pow(lz.im,2));
  return Wynik;
}
/*!
 * Oblicza modul z liczby zespolonej.
 * Argumenty:
 *    lz - liczba zespolona,
 *    
 * Zwraca:
 *    modul liczby zespolonej.
 */

double LZespolona::modul () const 
{
  double modulo=sqrt(pow(re,2)+pow(im,2));
  return modulo;
}

double abs (LZespolona lz) /*********************************/
{
  double Wynik=lz.modul();
  return Wynik;
}

LZespolona operator / (LZespolona lz, double r)
{
  LZespolona Wynik;
  if (r!=0)
    {
      Wynik.re = lz.re/r;
      Wynik.im = lz.im/r;
    }
  return Wynik;
}
/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywista.
 * Argumenty:
 *    lz - liczba zespolona, ktora chcemy podzielic,
 *    r - liczba rzeczywista, przez ktora dzielimy liczbe zepolona.
 * Zwraca:
 *    Liczbe zespolona podzielona przez liczbe rzeczywista.
 */

LZespolona Utworz (double re, double im) /***/
{
  LZespolona lz;
  lz.re = re;
  lz.im = im;
  return lz;
}
/*!
 * Tworzy liczbe zespolona.
 * Argumenty:
 *    re - czesc rzeczywista liczby zespolonej, bedaca liczba rzeczywista,
 *    im - czesc urojona liczby zespolonej, bedaca liczba rzeczywista.
 * Zwraca:
 *    Liczbe zespolona zlozona z dwoch czesci: rzeczywistej i urojonej przekazanych jako parametry.
 */

void Wyswietl (LZespolona lz) /***/
{
  cout<<"("<<lz.re<<std::showpos<<lz.im<<std::noshowpos<<"i)\n";
}
/*!
 * Wyswietla liczbe zespolona w ustalonym formacie.
 * Argumenty:
 *    lz - liczba zespolona ktora chcemy wyswietlic,
 *    
 * Zwraca:
 *    void.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */


LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik.re = (Skl1.re - Skl2.re);
  Wynik.im = (Skl1.im - Skl2.im);
  return Wynik;
}
/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmoawania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.im * Skl2.re) + (Skl1.re * Skl2.im);
  return Wynik;
}
/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  LZespolona Sprze=Sprzezenie(Skl2);
  double Mod=Modul2(Skl2);
  Wynik= (Skl1 * Sprze) / pow(Mod,2);
  return Wynik;  
}
/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow bedacych liczbami zespolonymi, przekazanych jako parametry.
 */

bool operator == (LZespolona  Skl1,  LZespolona  Skl2){
double epsilon=0.0000000000000000001;
if(abs(Skl1.re-Skl2.re)<epsilon && abs(Skl1.im-Skl2.im)<epsilon)
return true;
else
return false;
}

bool operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  return !(Skl1==Skl2);
}

bool operator == (LZespolona Skl1, double Skl2)
{
  double epsilon= 0.0000000000000001;
  if (abs(Skl1.re-Skl2)<=epsilon && abs(Skl1.im-Skl2)<=epsilon)
    return true;
  else
    return false;
}
/*!
 * Porownuje dwie liczby zespolone i sprawdza, czy sa takie same.
 * Argumenty:
 *    Skl1 - pierwszy skladnik porownania,
 *    Skl2 - drugi skladnik porownania.
 * Zwraca:
 *    Wartosc true, gdy liczby przekazane przez parametry a takie same.
 *    Wartosc false, gdy liczby przekazane przez parametry sa od siebie rozne.
 */

bool operator != (LZespolona Skl1, double Skl2)
{
  return !(Skl1==Skl2);
}

std::istream & operator >> (std::istream & strm,  LZespolona &Liczba) 
{
  char znak[3];
  if(!(cin>>znak[0]>>Liczba.re>>Liczba.im>>znak[1]>>znak[2]) || (znak[0]!= '(' || znak[1]!='i' || znak[2]!=')'))
      strm.setstate(std::ios::failbit); 	    
  return strm;
} 

std::ostream & operator << (std::ostream & strm, const LZespolona &Liczba)
{
  return strm<<"("<<Liczba.re<<std::showpos<<Liczba.im<<std::noshowpos<<"i)";
}

