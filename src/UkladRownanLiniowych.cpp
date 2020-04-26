#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/UkladRownanLiniowych.hh"
#include <cmath>
using namespace std;

const Macierz UkladRownanLiniowych::wstaw_kolumne (int i, Macierz M, Wektor W) const
{
    if (i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }   
    M=M.transpozycja();
    M[i]=W;
    M=M.transpozycja();
    return M;
}

void UkladRownanLiniowych::blad (UkladRownanLiniowych X, Wektor wynik) const
{
    cout<<endl<<"Dlugosc wektora bledu: "<<sqrt((A*wynik-W)*(A*wynik-W))<<endl;
    cout<<"Wektor bledow: "<<A*wynik-W<<endl;
}

const Wektor UkladRownanLiniowych::Cramer (UkladRownanLiniowych X) const
{
    Wektor wynik;
    int czy_zero=0;
    double wyz=A.wyznacznik();
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[i]=wstaw_kolumne(i,A,W).wyznacznik();
        if (wynik[i]==0)
        czy_zero++;
    }
    if (wyz==0 && czy_zero==ROZMIAR)
    {
        cout<<endl<<"Uklad ma nieskonczenie wiele rozwiazan"<<endl;
        exit (0);
    }
    if (wyz==0 && czy_zero!=ROZMIAR)
    {
        cout<<endl<<"Uklad nie ma rozwiazan"<<endl;
        exit (0);
    }
    for (int i=0; i<ROZMIAR; i++)
        wynik[i]/=wyz; 
    return wynik;
} 

Macierz & UkladRownanLiniowych::get_A() 
{
    return A;
}

Wektor & UkladRownanLiniowych::get_W() 
{
    return W;
}  

void UkladRownanLiniowych::set_A(Macierz & in) const
{
    in=A;
}

void UkladRownanLiniowych::set_W(Wektor & in) const
{
    in=W;
}

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm>>UklRown.get_A()>>UklRown.get_W();
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    Macierz TMPM; Wektor TMPW;
    UklRown.set_A(TMPM);
    UklRown.set_W(TMPW);
    Strm<<"Macierz:"<<endl<<TMPM<<"Wektor:"<<endl<<TMPW;
    return Strm;
}

    

