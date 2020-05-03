#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/UkladRownanLiniowych.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"
#include <cmath>
using namespace std;

template <class TYP, int ROZM>
const Macierz<TYP,ROZM> UkladRownanLiniowych<TYP,ROZM>::wstaw_kolumne (int i, Macierz<TYP,ROZM> M, Wektor<TYP,ROZM> W) const
{
    if (i<0 || i>=ROZM)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }   
    M=M.transpozycja();
    M[i]=W;
    M=M.transpozycja();
    return M;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> UkladRownanLiniowych<TYP,ROZM>::Cramer (UkladRownanLiniowych<TYP,ROZM> X) const
{
    Wektor<TYP,ROZM> wynik;
    int czy_zero = 0;
    Macierz<TYP,ROZM> Mac;
    TYP wyz = A.wyznacznik_gauss(); 
    for (int i=0; i<ROZM; i++)
    {
        Mac = wstaw_kolumne(i,A,W);
        wynik[i] = Mac.wyznacznik_gauss();
        if (wynik[i] == 0.0)
        czy_zero++;
    }
    if (wyz == 0.0  && czy_zero == ROZM)
    {
        cout<<endl<<"Uklad ma nieskonczenie wiele rozwiazan"<<endl;
        exit (0);
    }
    if (wyz == 0.0 && czy_zero != ROZM)
    {
        cout<<endl<<"Uklad nie ma rozwiazan"<<endl;
        exit (0);
    }
    for (int i=0; i<ROZM; i++)
        wynik[i] = wynik[i] / wyz; 
    return wynik;
} 

template <class TYP, int ROZM>
const Macierz<TYP,ROZM> & UkladRownanLiniowych<TYP,ROZM>::get_A() const
{
    return A;
}

template <class TYP, int ROZM>
const Wektor<TYP,ROZM> & UkladRownanLiniowych<TYP,ROZM>::get_W() const
{
    return W;
}  

template <class TYP, int ROZM>
void UkladRownanLiniowych<TYP,ROZM>::set_A(Macierz<TYP,ROZM> & in) 
{
    A=in;
}

template <class TYP, int ROZM>
void UkladRownanLiniowych<TYP,ROZM>::set_W(Wektor<TYP,ROZM> & in) 
{
    W=in;
}

template <class TYP, int ROZM>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZM> &UklRown)
{
    
    Wektor<TYP,ROZM> TMPW;
    Macierz<TYP,ROZM> TMPM;
    Strm>>TMPM>>TMPW;
    TMPM=TMPM.transpozycja();
    UklRown.set_A(TMPM);
    UklRown.set_W(TMPW);
    return Strm;    
}

template <class TYP, int ROZM>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZM> &UklRown)
{
    Macierz<TYP,ROZM> TMPM = UklRown.get_A();
    Wektor<TYP,ROZM> TMPW = UklRown.get_W();
    for (int i=0; i<ROZM; i++)
    {
        Strm<<TMPM[i]<<" ["<<TMPW[i]<<"]"<<endl;
    }
    return Strm;
}
    

