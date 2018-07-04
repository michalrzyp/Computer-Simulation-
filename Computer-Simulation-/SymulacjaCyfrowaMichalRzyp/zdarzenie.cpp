#include "zdarzenie.h"

Zdarzenie::Zdarzenie(double time)
{
  czas_ = time;
}
Zdarzenie::Zdarzenie()
{

}

Zdarzenie::~Zdarzenie()
{
}

double Zdarzenie::Czas() const
{
  return czas_;
}
int Zdarzenie::ZwrocId() const
{
  return id_;
}