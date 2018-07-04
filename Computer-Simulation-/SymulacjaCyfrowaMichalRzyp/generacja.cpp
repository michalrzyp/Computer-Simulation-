#include "generacja.h"
#include <iostream>
#include"nasluch.h"
#include<fstream>
#include<math.h>
#include"statystyki.h"
using namespace std;
Generacja::Generacja(double czas, int id, Generator *CTP, Generator *CGP, double koniec)
{
  czas_zdarzenia_ = czas;
  id_ = id;
  priorytet_ = 1;
  ctp_ = CTP;
  cgp_ = CGP;
  //Zaokraglanie czasu do dziesiatej czesci milisekundy
  czas_nastepnego_ = cgp_->RozkladWykladniczy();
  czas_nastepnego_ = floor(czas_nastepnego_ * 10);
  czas_nastepnego_ /= 10;
  //
  czas_konca_ = koniec;
}

Generacja::~Generacja()
{
}

int Generacja::Priorytet() const
{
  return priorytet_;
}

double Generacja::Czas() const
{
  return czas_zdarzenia_;
}

Zdarzenie* Generacja::wykonaj(Siec &siec)
{
  //Tworzenie pakietu
  Pakiet *nowy = new Pakiet(czas_zdarzenia_, ctp_->LosujLiczbeCalkowita(1, 10));
  //Aktualizacja statystyk
  if (Statystyki::faza_poczatkowa_ == 0)
    Statystyki::ilosc_pakietow_++;
  //Zaplanuj nasluch kanalu
  if (siec.nadajniki_[id_]->Pusty() == true)
  {
    Zdarzenie *nasluch = new Nasluch(czas_zdarzenia_, id_, nowy);
    siec.terminarz_.DodajZdarzenie(nasluch);
  }
  // 1. Ustaw pakiet w buforze
  siec.nadajniki_[id_]->DodajPakiet(nowy);
  siec.log_->WriteLog(siec.log_->kGeneracja, czas_zdarzenia_, id_);
  // 2. Zaplanuj kolejne zdarzenie
  if (czas_nastepnego_ <= czas_konca_)
  {
    Zdarzenie *nowy_pakiet = new Generacja(czas_zdarzenia_ + czas_nastepnego_, id_, ctp_, cgp_, czas_konca_);
    return nowy_pakiet;
  }
  return nullptr;
}

int Generacja::ZwrocId() const
{
  return id_;
}