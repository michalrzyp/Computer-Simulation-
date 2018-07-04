#ifndef NASLUCH_H_
#define NASLUCH_H_
#include"zdarzenie.h"
#include"siec.h"
class Nasluch : public Zdarzenie
{
public:
  Nasluch(double czas, int id, Pakiet *aktualny);
  ~Nasluch();
  Zdarzenie* wykonaj(Siec &siec);
  double Czas() const;
  int ZwrocId()const;
  int Priorytet() const;
private:
  double czas_;
  int id_;
  int priorytet_;
  Pakiet *aktualny_;
};
#endif

