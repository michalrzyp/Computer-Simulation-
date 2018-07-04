#include "wyslanieACK.h"
#include<iostream>

WyslanieACK::WyslanieACK(int id)
{
  numer_odbiornika_ = id;
}

WyslanieACK::~WyslanieACK()
{
}

bool WyslanieACK::wykonaj(Siec &siec)
{
  if (siec.odbiorniki_[numer_odbiornika_]->Ack() == true)
  {
    czas_ = siec.czas_symulacji_;
    siec.nadajniki_[numer_odbiornika_]->UstawPotwierdzenie(true);
    siec.log_->WriteLog(siec.log_->kAck, czas_, numer_odbiornika_);
    siec.odbiorniki_[numer_odbiornika_]->UstawAck(false);
    return true;
  }
  return false;
}