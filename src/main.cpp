#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/UkladRownanLiniowych.hh"
using namespace std;

int main()
{
  /*
  Macierz<LZespolona,3> M;
  cin >> M;
  cout<<endl<<"Macierz, z której porównuję wyznaczniki:"<<endl;
  cout<<M;
  cout << "Wyznacznik sarrus:" << M.wyznacznik() << endl;
  cout << "Wyznacznik gauss:" << M.wyznacznik_gauss() << endl;
  */
  UkladRownanLiniowych<LZespolona,5> X;
  cout << "Wpisz macierz i wektor:" << endl;
  cin >> X;  /*DANE W PLIKU dane.txt SĄ Z PDFA OD PANA KRECZMERA*/
  cout << "Reprezentacja wpisanego ukladu rownan:" << endl;
  cout << X;
  Wektor<LZespolona,5> wynik = X.Cramer(X);
  cout << "Rozwiazanie ukladu rownan:" << endl << wynik << endl;
}
