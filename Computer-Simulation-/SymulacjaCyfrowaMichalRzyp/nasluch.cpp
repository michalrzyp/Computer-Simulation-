#include "nasluch.h"
#include<iostream>
#include"transmisja.h"

Nasluch::Nasluch(double czas, int id, Pakiet *aktualny)
{
  id_ = id;
  czas_ = czas;
  priorytet_ = 1;
  aktualny_ = aktualny;
}

Nasluch::~Nasluch()
{
  aktualny_ = nullptr;
}
int Nasluch::Priorytet() const
{
  return priorytet_;
}

Zdarzenie* Nasluch::wykonaj(Siec &siec)
{
  if (siec.nadajniki_[id_]->Pusty() == true) return nullptr;
  if (siec.kanal_->stan_kanalu_ == false)
  {
    aktualny_->CzyRetransmisja() == true ? aktualny_->CsmaCa()->UstawDifs(-1.0) : aktualny_->CsmaCa()->ZmniejszDifs();
    if (aktualny_->CzyOpozniony() == true && aktualny_->CsmaCa()->ZwrocDifs() < 0.0)
      aktualny_->CsmaCa()->ZmniejszBt();
  }
  else
  {
    if (aktualny_->CzyOpozniony() == false)
      aktualny_->CsmaCa()->UstawDifs(2.0);

    aktualny_->UstawOpoznienie(true);

    if (aktualny_->CsmaCa()->ZwrocBt() <= 0)
      aktualny_->CsmaCa()->UstawBt();
  }
  if (aktualny_->CsmaCa()->ZwrocDifs() < 0.0  && aktualny_->CsmaCa()->ZwrocBt() <= 0)
  {
    siec.nadajniki_[id_]->ZezwolWyslac(true);
    aktualny_->CsmaCa()->UstawBt(0);
    aktualny_->CsmaCa()->UstawDifs(2.0);
    aktualny_->Retransmisja(false);
    Zdarzenie *transmisja = new Transmisja(czas_, id_);
    return transmisja;
  }
  siec.log_->WriteLog(siec.log_->kNasluch, czas_, id_);
  Zdarzenie *nasluch = new Nasluch(czas_ + 0.5, id_, aktualny_);
  return nasluch;
}

double Nasluch::Czas() const
{
  return czas_;
}
int Nasluch::ZwrocId()const
{
  return id_;
}