#include "siec.h"
#include<iostream>
Siec::Siec(bool tryb, int numer)
{
  czas_symulacji_ = 0.0;
  tryb_krokowy_ = tryb;
  log_ = new Zapis(tryb_krokowy_);
  for (int i = 0; i < l_urzadzen; ++i)
  {
    nadajniki_.push_back(new Nadajnik(i));
  }
  for (int i = 0; i < l_urzadzen; ++i)
  {
    odbiorniki_.push_back(new Odbiornik(i));
  }
  kanal_ = new Kanal();
  zajetosc_kanalu_ = kanal_->stan_kanalu_;
  kolizja_ = kanal_->kolizja_;
  numer_symulacji_ = numer;
}

Siec::~Siec()
{
  nadajniki_.clear();
  odbiorniki_.clear();
  delete kanal_;
  delete log_;
}
