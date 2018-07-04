#include "pakiet.h"
#include <cstdlib>

Pakiet::Pakiet(double czas_wystapienia, int CTP)
{
  czas_ = czas_wystapienia;
  retransmisja_ = false;
  ctp_ = CTP;
  liczba_retransmisji_ = 0;
  csma_ca_ = new Protokol();
}

Pakiet::~Pakiet()
{
  delete csma_ca_;
  csma_ca_ = nullptr;
}

double Pakiet::Czas() const
{
  return czas_;
}

int Pakiet::ZwrocCtp()
{
  return ctp_;
}
int Pakiet::ZwrockCtiz() const
{
  return kCtiz_;
}
bool Pakiet::CzyRetransmisja()
{
  return retransmisja_;
}
void Pakiet::Retransmisja(bool stan)
{
  retransmisja_ = stan;
}

void Pakiet::ZwiekszLiczbeRetransmisji()
{
  liczba_retransmisji_++;
}
int Pakiet::ZwrocLiczbeRetransmisji()
{
  return liczba_retransmisji_;
}
Protokol* Pakiet::CsmaCa()
{
  return csma_ca_;
}
bool Pakiet::CzyOpozniony()
{
  return opoznienie_;
}
void Pakiet::UstawOpoznienie(bool stan)
{
  opoznienie_ = stan;
}