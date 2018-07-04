#include "nadajnik.h"

Nadajnik::Nadajnik(int id)
{
  potwierdzenie_ = false;
  id_nadajnika_ = id;
  status_ = false;
}

Nadajnik::~Nadajnik()
{
  while (!bufor_.empty())
  {
    Pakiet* f2 = bufor_.front();
    bufor_.pop();
    delete f2;
  }
}

void Nadajnik::DodajPakiet(Pakiet *pakiet)
{
  bufor_.push(pakiet);
}

bool Nadajnik::Pusty()
{
  return bufor_.empty();
}
int Nadajnik::ZwrocId()
{
  return id_nadajnika_;
}

bool Nadajnik::CzyWyslac()
{
  return status_;
}

void Nadajnik::ZezwolWyslac(bool status)
{
  status_ = status;
}

Pakiet* Nadajnik::ZdejmijPakiet()
{
  Pakiet *p;
  p = bufor_.front();
  return p;
}
void Nadajnik::UsunPakiet()
{
  bufor_.pop();
}

void Nadajnik::UstawPotwierdzenie(bool stan)
{
  potwierdzenie_ = stan;
}

bool Nadajnik::Potwierdzenie()
{
  return potwierdzenie_;
}
