#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <cmath>
#include <iostream> 
#include <fstream> 
#include <vector>

#define M 2147483647.0
#define Q 127773 
#define R 2836 
#define A 16807
#define Ziarna 156
#define  Wielkosc_Proby 1000000
// Klasa odpowiedzialna za generowanie ziaren oraz liczb 
class Generator
{
public:
  Generator();
  Generator(double ziarno, double lambda);
  ~Generator();
  //Funkcja do generowania liczb rzeczywistych z przedziału <0,1>
  double RozkladRownomierny(int dol, int gora);
  //Funkcja do generowania liczb rzeczywistych zgodnie z rozkładem wykładniczym o intensywności lambda 
  double RozkladWykladniczy();
  //Funkcja do losowania liczby całkowitej z zakresu <poczatek,koniec> 
  int LosujLiczbeCalkowita(int poczatek, int koniec);
  // Funkcja tworząca plik z ziarnami 
  void GenerujZiarna(int liczba_ziaren);
  // Funkcja to wczytania ziaren 
  void WczytajZiarna();
  // Funkcja do utworzenia histogramu rozkladu rownomiernego 
  void RozkladRownomiernyTest();
  // Funkcja to utworzenia histogramu rozkladu wykladniczego
  void RozkladWykladniczyTest();
  // Funkcja to utworzenia histogramu rozkladu jednostajnego
  void RozkladJednostajnyTest();
  void GeneracjaTablicyZiaren();
  double get_ziarno();
  //double get_lambda();
private:
  double ziarno_;// aktualna wartość ziarna 
  std::vector<double> tablica_ziaren_;
  double lambda_;
};
#endif
