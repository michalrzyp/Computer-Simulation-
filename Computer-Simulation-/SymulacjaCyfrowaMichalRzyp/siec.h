#ifndef SIEC_H_
#define SIEC_H_

#include <vector>
#include "nadajnik.h"
#include "odbiornik.h"
#include "kanal.h"
#include "pakiet.h"
#include "kalendarz.h"
#include "zapis.h"

#define l_urzadzen 12
struct Siec
{
  Siec(bool tryb, int numer);
  ~Siec();
  const int kLiczbaNadajnikow_ = l_urzadzen; //sta�a liczba nadajnik�w
  const int kLiczbaOdbiornikow_ = l_urzadzen; //sta�a liczba odbiornik�w
  std::vector<Nadajnik*> nadajniki_; //wektor nadajnik�w
  std::vector<Odbiornik*> odbiorniki_; //wektor odbiornik�w 
  Kanal *kanal_;
  Zapis *log_;
  bool tryb_krokowy_, zajetosc_kanalu_, kolizja_;
  Kalendarz terminarz_;
  double czas_symulacji_;
  ofstream logfile_;
  int numer_symulacji_;//pomocnicza zmienna do zbierania danych
};
#endif //SIEC_H_
