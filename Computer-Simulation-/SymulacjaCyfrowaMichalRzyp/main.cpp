#include <iostream>
#include <cstdlib>
#include <queue>
#include <time.h>
#include "pakiet.h"
#include "kanal.h"
#include "odbiornik.h"
#include "nadajnik.h"
#include "siec.h"
#include "generator.h"
#include"kalendarz.h"
#include"symulacja.h"
#include"zapis.h"
#include"statystyki.h"
#include"zdarzenie.h"
using namespace std;

void GeneratorTest(); // Test generatorów
int main()
{
  char znak;
  bool tryb_krokowy;
  double czas_konca, lambda;
  int liczba_symulacji, faza_poczatkowej;
  //GeneratorTest();
 /* std::cout << "Czy uruchomic symulacje w trybie krokowym? t/n : ";
  cin >> znak;
  if (znak == 't' || znak == 'T') tryb_krokowy = true;
  else tryb_krokowy = false;
  cout << "Podaj koniec fazy poczatkowej: ";
  cin >> faza_poczatkowej;
  cout << "Podaj czas konca symulacji: ";
  cin >> czas_konca;
  cout << "Podaj liczbe symulacji: ";
  cin >> liczba_symulacji;
  if (liczba_symulacji > 12)
  {
    cout << "Za duzo symulacji. Max 12";
    liczba_symulacji = 12;
  }
  cout << "Podaj wartosc lambda: ";
  cin >> lambda;*/
  ifstream file;
  file.open("parametry.txt");
  if (!file)
    cout << "Nie udalo sie otworzy pliku ziarna.txt" << endl;
  else
  {
    file >> tryb_krokowy;
    file >> faza_poczatkowej;
    file >> czas_konca;
    file >> liczba_symulacji;
    file >> lambda;
  }
  file.close();
  cout << czas_konca << endl;
  cout << endl;
  Symulacja *k = new Symulacja(liczba_symulacji, faza_poczatkowej, czas_konca, tryb_krokowy, lambda);
  k->run();
  delete k;

  system("pause");
}

void GeneratorTest()
{
  Generator generator;
  generator.GeneracjaTablicyZiaren();
 /* generator.GenerujZiarna(1000000);
  std::cout << "Wczytywanie ziaren" << endl;
  generator.WczytajZiarna();
  std::cout << "Koniec wczytywania ziaren" << endl;
  std::cout << "Generacja rozkladu rownomiernego" << endl;
  generator.RozkladRownomiernyTest();
  std::cout << "Generacja rozkladu wykladniczego" << endl;
  generator.RozkladWykladniczyTest();
  std::cout << "Generacja rozkladu jednostajnego" << endl;
  generator.RozkladJednostajnyTest();*/
  //system("pause");
}