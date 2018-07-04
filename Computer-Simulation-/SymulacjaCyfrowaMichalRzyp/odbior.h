#ifndef ODBIOR_H_
#define ODBIOR_H_

#include"zdarzenie.h"
#include"siec.h"

class Odbior : public Zdarzenie
{
public:
  Odbior(double czas, int id);
  ~Odbior();
  Zdarzenie* wykonaj(Siec &siec);
  double Czas() const;
  int ZwrocId()const;
  int Priorytet() const;
private:
  double czas_odbioru_;
  int id_;
  int priorytet_;
};
#endif
