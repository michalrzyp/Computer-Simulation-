#include "kolizja.h"
#include<iostream>

Kolizja::Kolizja(int id)
{
  czas_ = 0.0;
  id_ = id;
}

Kolizja::~Kolizja()
{
}

bool Kolizja::wykonaj(Siec &siec)
{
  if (siec.kanal_->liczba_pakietow_ > 1 && siec.kanal_->stan_kanalu_ == true)
  {
    siec.kolizja_ = true;
    siec.kanal_->max_czas_zajetosci_ = siec.czas_symulacji_;
    for (int i = 0; i < l_urzadzen; ++i)
    {
      if (siec.kanal_->bufor_aktualnych_[i] != nullptr)
      {
        siec.kanal_->bufor_aktualnych_[i]->Retransmisja(true);
        if (siec.kanal_->max_czas_zajetosci_ <= (siec.kanal_->bufor_aktualnych_[i]->ZwrocCtp() + siec.czas_symulacji_ + siec.kanal_->bufor_aktualnych_[i]->ZwrockCtiz()))
          siec.kanal_->max_czas_zajetosci_ = (siec.kanal_->bufor_aktualnych_[i]->ZwrocCtp() + siec.czas_symulacji_ + siec.kanal_->bufor_aktualnych_[i]->ZwrockCtiz());
      }
    }
    czas_ = siec.czas_symulacji_;
    siec.log_->WriteLog(siec.log_->kKolizja, czas_, 0);
    return true;
  }
  return false;
}
