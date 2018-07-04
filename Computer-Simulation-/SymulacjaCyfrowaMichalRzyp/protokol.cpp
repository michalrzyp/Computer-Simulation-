#include "Protokol.h"
#include <algorithm>  
#include "generator.h"
Protokol::Protokol()
{
  difs_ = 2.0;
  cw_min_ = 0;//31;
  cw_max_ = 3; //255;
  cw_ = cw_min_;
  bt_ = 0;
  generator_bt_ = new Generator();
}

Protokol::~Protokol()
{
  delete generator_bt_;
  generator_bt_ = nullptr;
}
void Protokol::UstawNoweCw()
{
  cw_ = std::min((2 * (cw_ + 1) - 1), cw_max_);
}

void Protokol::UstawBt()
{
  bt_ = generator_bt_->LosujLiczbeCalkowita(0, cw_);
}
void Protokol::UstawBt(int czas)
{
  bt_ = czas;
}
void Protokol::ZmniejszDifs()
{
  difs_ -= 0.5;
}

double Protokol::ZwrocDifs()
{
  return difs_;
}
void Protokol::UstawDifs(double czas)
{
  difs_ = czas;
}

int Protokol::ZwrocBt()
{
  return bt_;
}

int Protokol::ZwrocCwMin()
{
  return cw_min_;
}

int Protokol::ZwrocCwMax()
{
  return cw_max_;
}

int Protokol::ZwrocCw()
{
  return cw_;
}
void Protokol::ZmniejszBt()
{
  bt_ -= 1;
}