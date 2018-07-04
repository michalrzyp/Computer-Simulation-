#include "odbiornik.h"

Odbiornik::Odbiornik(int id)
{
  ack_ = false;
  id_odbiornika_ = id;
  aktualny = nullptr;
}

Odbiornik::~Odbiornik()
{
  aktualny = nullptr;
  delete aktualny;
}
bool Odbiornik::Ack()
{
  return ack_;
}
void Odbiornik::UstawAck(bool stan)
{
  ack_ = stan;
}
int Odbiornik::ZwrocId()
{
  return id_odbiornika_;
}
Pakiet* Odbiornik::ZwrocPakiet()
{
  return aktualny;
}

void Odbiornik::UstawBiezacyPakiet(Pakiet *a)
{
  aktualny = a;
}