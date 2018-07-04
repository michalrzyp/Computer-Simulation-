#ifndef TRANSMISJA_H_
#define TRANSMISJA_H_
#include"siec.h"
class Transmisja :public Zdarzenie
{
public:
  Transmisja(double czas, int id);
  ~Transmisja();
  Zdarzenie* wykonaj(Siec &siec);
  double Czas() const;
  int ZwrocId()const;
  int Priorytet() const;
private:
  int id_;
  double czas_;
  int priorytet_;
};
#endif
