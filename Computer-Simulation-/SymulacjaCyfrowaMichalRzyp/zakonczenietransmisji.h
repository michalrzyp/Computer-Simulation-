#ifndef ZAKONCZENIETRANSMISJI_H_
#define ZAKONCZENIETRANSMISJI_H_
#include"zdarzenie.h"
#include"siec.h"
class ZakonczenieTransmisji :public Zdarzenie
{
public:
  ZakonczenieTransmisji(double czas, int id);
  ~ZakonczenieTransmisji();
  Zdarzenie* wykonaj(Siec &siec);
  double Czas() const;
  int ZwrocId()const;
  int Priorytet() const;
private:
  double czas_;
  int id_;
  int priorytet_;
};
#endif

