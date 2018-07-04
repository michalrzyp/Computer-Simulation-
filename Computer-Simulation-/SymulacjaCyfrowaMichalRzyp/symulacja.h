#ifndef SYMULACJA_H
#define SYMULACJA_H_

#include"siec.h"
#include"zapis.h"
#include"statystyki.h"
#include"kalendarz.h"
#include"zdarzenie.h"
#include "generator.h"

#include"generacja.h"
#include"nasluch.h"
#include"odbior.h"
#include"zakonczenietransmisji.h"

#include"wyslanieACK.h"
#include"retransmisja.h"
#include"transmisja.h"
#include"kolizja.h"

class Symulacja
{
public:
  Symulacja(int liczba_symulacji, int faza_poczatkowa, double czas_symulacji, bool tryb, double lambda);
  ~Symulacja();
  void run();
private:
  bool tryb_krokowy_;
  double czas_konca_;
  int faza_poczatkowa_;
  int liczba_symulacji_;
  double lambda_;
  double tablica_ziaren_[Ziarna];
  Generator *CTP;
  Generator *CGP[l_urzadzen];
  ofstream log_;
};

#endif