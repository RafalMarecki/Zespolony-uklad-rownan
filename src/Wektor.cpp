#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"
#include <iostream>
#include <cmath>
using namespace std;

template <class TYP, int ROZM>
Wektor<TYP, ROZM>::Wektor(TYP x, TYP y, TYP z)
{
    tabW[0]=x;
    tabW[1]=y;
    tabW[2]=z;
}

template <class TYP, int ROZM>
Wektor<TYP, ROZM>::Wektor()
{
    for (int i=0; i<ROZM; i++)
    {
        tabW[i]=0;
    }
}

template <class TYP, int ROZM>
TYP & Wektor<TYP, ROZM>::operator[](int i) 
{
    if(i<0 || i>=ROZM)
    {
        cerr<<"Blad-jestes poza tablica!";
        exit(1);
    }
    return tabW[i];
}

template <class TYP, int ROZM>
const TYP & Wektor<TYP, ROZM>::operator[](int i) const
{
    if(i<0 || i>=ROZM)
    {
        cerr<<"Blad-jestes poza tablica!";
        exit(1);
    }
    return tabW[i];
}

template <class TYP, int ROZM>
void Wektor<TYP, ROZM>::wpisz()
{
    for (int i=0; i<ROZM; i++)
    {
        cout<<"Wpisz wartosc:";
        cin>>tabW[i];
    }
}

template <class TYP, int ROZM>
void Wektor<TYP, ROZM>::wypisz ()
{
    for (int i=0; i<ROZM; i++)
    {
        cout<<i+1<<" wartosc:"<<tabW[i]<<endl;
    }
}

template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZM> &Wek)
{
    for (int i=0; i<ROZM; i++)
    {
        Strm>>Wek[i];
    }
    return Strm;
}

template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZM> &Wek)
{
    cout<<"[";
    for (int i=0; i<ROZM-1; i++)
    {
        cout<<Wek[i]<<" ";
    }
    cout<<Wek[ROZM-1]<<"]";
    return Strm;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator + (const Wektor<TYP, ROZM> & W2) const
{
    Wektor <TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[i]=tabW[i]+W2[i];   
    }
    return wynik;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator - (const Wektor<TYP, ROZM> & W2) const
{
    Wektor <TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[i]=tabW[i]-W2[i];   
    }
    return wynik;
}

template <class TYP, int ROZM>
const TYP Wektor<TYP, ROZM>::operator * (const Wektor<TYP, ROZM> & W2) const /* Iloczyn skalarny */
{
    TYP wynik, iloczyn;
    for (int i=0; i<ROZM; i++)
    {
        iloczyn=tabW[i]*W2[i];
        wynik= wynik+iloczyn;
    }
    return wynik;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator * (TYP l) const /* Wektor razy liczba */ /*const x2*/
{
    Wektor <TYP,ROZM> wynik;
    for (int i=0; i<ROZM; i++)
    {
        wynik[0]=tabW[i]*l;
    }
    return wynik;
}

/*
template <class TYP, int ROZM> 
const Wektor<TYP,ROZM> Wektor<TYP, ROZM>::operator / (TYP l) const 
{
    Wektor <TYP,ROZMIAR> wynik;
    if (l==0.0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[i]=tabW[i]/l;
    }
    return wynik;
}
*/

template <class TYP, int ROZM>
bool Wektor<TYP, ROZM>::operator == (const Wektor<TYP, ROZM> & W2) const
{
    double epsilon=0.000000000000001; int i;
    for (i=0; i<ROZM; i++)
    {
        if(this->tabW[i]-W2[i]>epsilon)
        return false;
    }
    return true;
}

template <> bool Wektor<LZespolona,5>::operator == (const Wektor<LZespolona,5> & W2) const  /********/
{
    Wektor<LZespolona,5> Wynik;
    double epsilon=0.00000001;
    int i;
    for(i=0;i<5;i++)
    if(abs(tabW[i].modul()-W2[i].modul())>epsilon)
    return false;
    return true;
}

template <> bool Wektor<LZespolona,3>::operator==(const Wektor<LZespolona,3> & W2) const  /********/
{
    Wektor<LZespolona,3> Wynik;
    double epsilon=0.00000001;
    int i;
    for(i=0;i<3;i++)
    if(abs(tabW[i].modul()-W2[i].modul())>epsilon)
    return false;
    return true;
}

template <class TYP, int ROZM>
bool Wektor<TYP, ROZM>::operator != (const Wektor<TYP, ROZM> & W2) const
{      
    return !(*this==W2);
}
/*
template <class TYP, int ROZM>
const TYP Wektor<TYP, ROZM>::dlugosc () const
{
    double wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik+=pow(tabW[i],2);
    }
    return sqrt(wynik);
}
*/
/*
template std::istream & operator>>(std::istream &strm, Wektor<double,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<double,ROZMIAR> &W);
template const Wektor <double,ROZMIAR> Wektor <double,ROZMIAR>::operator+ (const Wektor <double, ROZMIAR> & W2) const;
template const Wektor <double,ROZMIAR> Wektor <double,ROZMIAR>::operator- (const Wektor <double, ROZMIAR> & W2) const;
template const double Wektor <double,ROZMIAR>::operator * (const Wektor <double, ROZMIAR> & W2) const;
template const Wektor <double,ROZMIAR> Wektor <double,ROZMIAR>::operator * (double l) const;
template const Wektor <double,ROZMIAR> Wektor <double,ROZMIAR>::operator / (double l) const;
template bool Wektor <double,ROZMIAR>::operator == (const Wektor <double, ROZMIAR> & W2) const;
template bool Wektor <double,ROZMIAR>::operator != (const Wektor <double, ROZMIAR> & W2) const;
template const double Wektor <double,ROZMIAR>::dlugosc () const;

template std::istream & operator>>(std::istream &strm, Wektor<LZespolona,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<LZespolona,ROZMIAR> &W);
template const Wektor <LZespolona,ROZMIAR> Wektor <LZespolona,ROZMIAR>::operator+ (const Wektor <LZespolona, ROZMIAR> & W2) const;
template const Wektor <LZespolona,ROZMIAR> Wektor <LZespolona,ROZMIAR>::operator- (const Wektor <LZespolona, ROZMIAR> & W2) const;
template const LZespolona Wektor <LZespolona,ROZMIAR>::operator * (const Wektor <LZespolona, ROZMIAR> & W2) const;
template const Wektor <LZespolona,ROZMIAR> Wektor <LZespolona,ROZMIAR>::operator * (LZespolona l) const; 
template const Wektor <LZespolona,ROZMIAR> Wektor <LZespolona,ROZMIAR>::operator / (LZespolona l) const; ,
template bool Wektor <LZespolona,ROZMIAR>::operator == (const Wektor <LZespolona, ROZMIAR> & W2) const;
template bool Wektor <LZespolona,ROZMIAR>::operator != (const Wektor <LZespolona, ROZMIAR> & W2) const;
*/




