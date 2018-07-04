#include "kanal.h"

Kanal::Kanal()
{
  stan_kanalu_ = false;
  liczba_pakietow_ = 0;
  kolizja_ = false;
  id_ = -1;
  max_czas_zajetosci_ = 0.0;
  for (int i = 0; i < 12; ++i)
  {
    bufor_aktualnych_.push_back(nullptr);
  }
}

Kanal::~Kanal()
{
  bufor_aktualnych_.clear();
}
