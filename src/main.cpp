#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/LZespolona.hh"
using namespace std;

int main()
{ 
  Wektor <LZespolona,ROZMIAR> X;
  cout<<"Wpisz wektor zespolony 1:"<<endl;
  cin>>X;  
  Wektor <LZespolona,ROZMIAR> Y;
  cout<<"Wpisz wektor zespolony 2:"<<endl;
  cin>>Y;  
  Wektor <double,ROZMIAR> Z;
  cout<<"Wpisz wektor rzeczywisty 1:"<<endl;
  cin>>Z;  
  Wektor <double,ROZMIAR> C;
  cout<<"Wpisz wektor rzeczywisty 2:"<<endl;
  cin>>C;  
  cout<<"IM.wektor1 + IM.wektor2 ="<<X+Y<<endl;
  cout<<"RE.wektor1 + RE.wektor2 ="<<Z+C<<endl;
}
/*
  UkladRownanLiniowych X;
  cout<<"Wpisz macierz i wektor:"<<endl;
  cin>>X;
  cout<<"Reprezentacja ukladu rownan:"<<endl;
  cout<<X;
  Wektor =X.Cramer(X);
  X.blad(X,wynik); 
  cout<<"Rozwiazanie ukladu rownan:"<<wynik<<endl;
  */