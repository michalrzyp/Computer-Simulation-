#include "odbior.h"
#include"zakonczenietransmisji.h"
#include"nasluch.h"

Odbior::Odbior(double czas, int id)
{
  id_ = id;
  czas_odbioru_ = czas;
  priorytet_ = 1;
}

Odbior::~Odbior()
{
}
int Odbior::Priorytet() const
{
  return priorytet_;
}
double Odbior::Czas() const
{
  return czas_odbioru_;
}
Zdarzenie* Odbior::wykonaj(Siec &siec)
{
  siec.odbiorniki_[id_]->UstawBiezacyPakiet(siec.kanal_->bufor_aktualnych_[id_]);
  if (siec.odbiorniki_[id_]->ZwrocPakiet() != nullptr)
  {
    siec.kanal_->bufor_aktualnych_[id_] = nullptr;
    czas_odbioru_ = siec.czas_symulacji_;
    if (siec.odbiorniki_[id_]->ZwrocPakiet()->CzyRetransmisja() == false)
    {
      siec.odbiorniki_[id_]->UstawAck(true);
      siec.log_->WriteLog(siec.log_->kOdbior, czas_odbioru_, id_);
    }
    else
    {
      siec.odbiorniki_[id_]->UstawAck(false);
    }
    Zdarzenie *koniec = new ZakonczenieTransmisji(czas_odbioru_ + siec.odbiorniki_[id_]->ZwrocPakiet()->ZwrockCtiz(), id_);
    siec.odbiorniki_[id_]->UstawBiezacyPakiet(nullptr);
    return koniec;
  }
  return nullptr;
}

int Odbior::ZwrocId()const
{
  return id_;
}