#include "zakonczenietransmisji.h"
#include<iostream>
#include"generacja.h"
#include"statystyki.h"
#include"nasluch.h"

ZakonczenieTransmisji::ZakonczenieTransmisji(double czas, int id)
{
  id_ = id;
  czas_ = czas;
  priorytet_ = 1;
}

ZakonczenieTransmisji::~ZakonczenieTransmisji()
{
}
int ZakonczenieTransmisji::Priorytet() const
{
  return priorytet_;
}

Zdarzenie* ZakonczenieTransmisji::wykonaj(Siec &siec)
{
  //W przypadku poprawnego odbioru konczymy oblusge pakietu w przeciwnym wypadku zwalniamy kanal po czasie najdluzszego pakietu
  // oraz planujemy ponowny nasluch kanalu
  if (siec.nadajniki_[id_]->Potwierdzenie() == true)
  {
    siec.kanal_->stan_kanalu_ = false;//zwolnienie kanalu
    siec.nadajniki_[id_]->UstawPotwierdzenie(false);
    siec.kanal_->liczba_pakietow_ = 0;
    siec.kanal_->id_ = -1;
    siec.kanal_->kolizja_ = false;
    czas_ = siec.czas_symulacji_;
    double czas_zycia = (czas_ - siec.nadajniki_[id_]->ZdejmijPakiet()->Czas());
    /*char buf[256];
    sprintf_s(buf, "testowy%d.txt", siec.numer_symulacji_);
    siec.logfile_.open(buf, ios::out | ios::app);
        siec.logfile_ << czas_zycia << endl;
    siec.logfile_.close();*/
    if (Statystyki::faza_poczatkowa_ == 0)
    {
      Statystyki::ilosc_odebrana_++;
      Statystyki::opoznienie_ += czas_zycia;
      Statystyki::odebrane_na_odbiornik[id_]++;
      Statystyki::liczba_retransmisji_ += siec.nadajniki_[id_]->ZdejmijPakiet()->ZwrocLiczbeRetransmisji();
    }
    else Statystyki::faza_poczatkowa_--;
    siec.kanal_->bufor_aktualnych_[id_] = nullptr;
    siec.nadajniki_[id_]->UsunPakiet();
    siec.log_->WriteLog(siec.log_->kZakonczenieTransmisji, czas_, id_);
  }
  else
  {
    if (siec.kanal_->max_czas_zajetosci_ == czas_ && siec.kanal_->stan_kanalu_ == true)
    {
      siec.kanal_->stan_kanalu_ = false;
      siec.kanal_->max_czas_zajetosci_ = 0.0;
    }
    //Zwolnienie kanalu po czasie CTP+CTIZ dla najdluzszego pakietu bioracego udzial w kolizji
  }
  if (siec.nadajniki_[id_]->Pusty() == false)
  {
    Zdarzenie *nasluch = new Nasluch(czas_, id_, siec.nadajniki_[id_]->ZdejmijPakiet());
    return nasluch;
  }
  else
  {
    return nullptr;
  }
}

double ZakonczenieTransmisji::Czas() const
{
  return czas_;
}
int ZakonczenieTransmisji::ZwrocId()const
{
  return id_;
}