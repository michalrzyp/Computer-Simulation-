#include "retransmisja.h"
#include<iostream>
#include"statystyki.h"

Retransmisja::Retransmisja(int id)
{
  licznik_ = 0;
  czas_ = 0.0;
  id_ = id;
}

Retransmisja::~Retransmisja()
{
}
bool Retransmisja::wykonaj(Siec &siec)
{
  if (siec.kolizja_ == true)
  {
    int nr = -1;
    czas_ = siec.czas_symulacji_;
    for (int i = 0; i < l_urzadzen; i++)
    {
      if (siec.nadajniki_[i]->Pusty() == false)
        siec.nadajniki_[i]->ZdejmijPakiet()->CzyRetransmisja() == true ? nr = i : nr = -1;
      if (nr >= 0)
      {
        siec.nadajniki_[nr]->ZdejmijPakiet()->CsmaCa()->UstawNoweCw();
        if (siec.nadajniki_[nr]->ZdejmijPakiet()->CsmaCa()->ZwrocCw() >= siec.nadajniki_[nr]->ZdejmijPakiet()->CsmaCa()->ZwrocCwMax())
        {
          siec.nadajniki_[nr]->UsunPakiet();
          if (Statystyki::faza_poczatkowa_ == 0)
          {
            Statystyki::liczba_straconych_++;
            Statystyki::stracone_na_nadajnik[nr]++;
          }
        }
        else
        {
          siec.nadajniki_[nr]->ZdejmijPakiet()->CsmaCa()->UstawBt();
          siec.nadajniki_[nr]->ZdejmijPakiet()->ZwiekszLiczbeRetransmisji();
          siec.nadajniki_[nr]->ZdejmijPakiet()->UstawOpoznienie(true);
        }
        siec.log_->WriteLog(siec.log_->kRetransmisja, czas_, nr);
      }
      nr = -1;
    }
    siec.kolizja_ = false;
    siec.kanal_->liczba_pakietow_ = 0;
    return true;
  }
  return false;
}