#include "transmisja.h"
#include<iostream>
#include"odbior.h"
#include"nasluch.h"
#include"statystyki.h"

Transmisja::Transmisja(double czas, int id)
{
  id_ = id;
  czas_ = czas;
  priorytet_ = 1;
}

Transmisja::~Transmisja()
{
}
int Transmisja::Priorytet() const
{
  return priorytet_;
}
Zdarzenie* Transmisja::wykonaj(Siec &siec)
{
    siec.kanal_->bufor_aktualnych_[id_] = siec.nadajniki_[id_]->ZdejmijPakiet();
    siec.kanal_->stan_kanalu_ = true;//zajecie kanalu 
    siec.kanal_->liczba_pakietow_++;
    czas_ = siec.czas_symulacji_;
    if(Statystyki::faza_poczatkowa_ == 0)
      Statystyki::oczekiwanie_ += (czas_ - siec.nadajniki_[id_]->ZdejmijPakiet()->Czas());
    siec.nadajniki_[id_]->ZezwolWyslac(false);
    siec.kanal_->max_czas_zajetosci_ = (siec.kanal_->bufor_aktualnych_[id_]->ZwrocCtp() + siec.czas_symulacji_ + siec.kanal_->bufor_aktualnych_[id_]->ZwrockCtiz());
    siec.log_->WriteLog(siec.log_->kTransmisja, czas_, id_);
    Zdarzenie *odbior = new Odbior(czas_ + siec.nadajniki_[id_]->ZdejmijPakiet()->ZwrocCtp(), id_);
    return odbior;
}

double Transmisja::Czas() const
{
  return czas_;
}
int Transmisja::ZwrocId()const
{
  return id_;
}