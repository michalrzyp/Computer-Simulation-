#include "generator.h"
#include<math.h>
using namespace std;
Generator::Generator()
{
  ziarno_ = 100;
}

Generator::Generator(double ziarno, double lambda)
{
  //ziarno_ = tablica_ziaren_.at(ziarno);
  ziarno_ = ziarno;
  lambda_ = lambda;
}

Generator::~Generator()
{ 
  tablica_ziaren_.clear();
}

double Generator::get_ziarno()
{
  return ziarno_;
}

double Generator::RozkladRownomierny(int dol, int gora)
{
  double x = ziarno_;
  int h = int(x / Q);
  x = A * (x - Q * h) - R * h;
  ziarno_ = x;
  if (x < 0) x += M;
  double c = dol, d = gora;
  return (x / M) * (d - c) + c;
}

double Generator::RozkladWykladniczy()
{
  return  -log(RozkladRownomierny(0, 1)) / lambda_;
}

int Generator::LosujLiczbeCalkowita(int poczatek, int koniec)
{
  return (static_cast<int> (poczatek + RozkladRownomierny(0, 1) * (koniec)));
}

void Generator::RozkladRownomiernyTest() {
  std::ofstream file;
  file.open("rownomierny.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  for (unsigned int i = 0; i < tablica_ziaren_.size(); i++)
    file << RozkladRownomierny(0, 1) << std::endl;
  file << std::flush;
  file.close();
}

void Generator::RozkladWykladniczyTest()
{
  std::ofstream file;
  file.open("wykladniczy.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  for (unsigned int i = 0; i < tablica_ziaren_.size(); i++)
    file << RozkladWykladniczy() << std::endl;
  file << std::flush;
  file.close();
}

void Generator::RozkladJednostajnyTest()
{
  std::ofstream file;
  file.open("jednostajny.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  for (unsigned int i = 0; i < tablica_ziaren_.size(); i++)
    file << LosujLiczbeCalkowita(1, 10) << std::endl;
  file << std::flush;
  file.close();
}

void Generator::GenerujZiarna(int liczba_ziaren)
{
  std::ofstream file;
  file.open("ziarna.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  ziarno_ = 100; // Generowanie ziaren i zapis do pliku 
  for (int i = 0; i < liczba_ziaren; i++)
  {
    double x = ziarno_;
    int h = static_cast<int>(x / Q);
    x = A*(x - Q*h) - R*h;
    if (x < 0) x += M;
    ziarno_ = x;
    file << ziarno_ << std::endl;
  }
  file << std::flush;
  file.close();
}

void Generator::WczytajZiarna()
{
  tablica_ziaren_.reserve(Wielkosc_Proby);
  std::ifstream file;
  file.open("ziarna.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  double tmp;
  while (!file.eof())
  {
    file >> tmp; tablica_ziaren_.push_back(tmp);
  }
  file.close();
}

void Generator::GeneracjaTablicyZiaren()
{
  GenerujZiarna(Wielkosc_Proby);
  WczytajZiarna();
  int krok = Wielkosc_Proby / Ziarna;
  std::ofstream file;
  file.open("tablica_ziaren.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  ziarno_ = 100; // Generowanie ziaren i zapis do pliku 
  for (int i = 0; i < Ziarna; i++)
  {
    file << tablica_ziaren_[i * krok] << std::endl;
  }
  file << std::flush;
  file.close();
}