#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
using namespace std;

Macierz::Macierz()
{
    Wektor X;
    for(int i; i<ROZMIAR; i++)
    {
        tabM[i]=X;
    }
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{    
    tabM[0]=A;
    tabM[1]=B;
    tabM[2]=C;
}

Wektor & Macierz::operator [] (int i)
{
    if (i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }
    return tabM[i];
}

const Wektor & Macierz::operator [] (int i) const
{
    if (i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }
    return tabM[i];
}

const Macierz Macierz::transpozycja () const
{
    Macierz A;
    for (int i=0; i<ROZMIAR; i++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            A[i][j]=tabM[j][i];
        }
    }
    return A;
}

std::istream & operator >> (std::istream &Strm, Macierz &Mac)
{   
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm>>Mac[i];
    }
    /*
    Strm>>Mac[0]>>Mac[1]>>Mac[2];
    */
    return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Macierz &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm<<Mac[i]<<endl;
    }
    return Strm;
}

const Wektor Macierz::operator* (const Wektor & W2) const /* Macierz*Wektor */ 
{
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[i]=tabM[i]*W2;
    }
    return wynik;
}

const Macierz Macierz::operator* (Macierz A) const /* Macierz*Macierz */
{
    Macierz B, wynik; 
    int i;
    A=A.transpozycja();                
    for (i=0; i<ROZMIAR; i++) 
    {
        B[i]=tabM[i];
    }        
    for (i=0; i<ROZMIAR; i++)
    {
        wynik[i]=B*A[i];
    }           
    return wynik.transpozycja();
}
/* Jesli bede mial problem i bede musiał napisac */
/* w nawiasie const Macierz & A, to po prostu podmienie */
/* i stworze sobie nowa zmienna typu Macierz zamiast */
/* pod A podpisywac A=A.transpozycja();. */
/* Nie robie tego, bo nie chce aby ta funkcja zmieniala wartosc A */

const Macierz Macierz::operator * (double l) const
{
    Macierz Wynik;
    for (int i=0; i<ROZMIAR; i++) 
    {
        Wynik[i]=tabM[i]*l;
    }
    return Wynik;
}

const Macierz Macierz::operator / (double l) const
{
    Macierz Wynik;
    if (l==0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<ROZMIAR; i++) 
    {
        Wynik[i]=tabM[i]/l;
    }
    return Wynik;
}

const Macierz Macierz::operator + (const Macierz & A) const
{
    Macierz wynik;
    for (int i=0; i<ROZMIAR; i++) 
    {
        wynik[i]=tabM[i]+A[i];
    }
    return wynik;
}

const Macierz Macierz::operator - (const Macierz & A) const
{
    Macierz wynik;
    for (int i=0; i<ROZMIAR; i++) 
    {
        wynik[i]=tabM[i]-A[i];
    }
    return wynik;
}

bool Macierz::operator == (const Macierz & A) const
{
    for (int i=0; i<ROZMIAR; i++)
    {
        if (tabM[i]!=A[i])
        return false;
    }
    return true;
}

bool Macierz::operator != (const Macierz & A) const
{
    for (int i=0; i<ROZMIAR; i++)
    {
        if (tabM[i]!=A[i])
        return true;
    }    
    return false;
}

const double Macierz::wyznacznik () const
{
    double wynik=tabM[0][0]*tabM[1][1]*tabM[2][2]  +  tabM[0][1]*tabM[1][2]*tabM[2][0]  +  tabM[0][2]*tabM[1][0]*tabM[2][1]  -  tabM[2][0]*tabM[1][1]*tabM[0][2]  -  tabM[2][1]*tabM[1][2]*tabM[0][0]  -  tabM[2][2]*tabM[1][0]*tabM[0][1];
    return wynik;
}



