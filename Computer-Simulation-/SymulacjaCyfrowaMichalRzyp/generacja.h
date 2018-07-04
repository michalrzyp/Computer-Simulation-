#ifndef GENERACJA_H_
#define GENERACJA_H_
#include"zdarzenie.h"
#include"siec.h"
#include"generator.h"
class Generacja : public Zdarzenie
{
public:
  Generacja(double czas, int id, Generator *CTPK, Generator *CGPK, double koniec);
  ~Generacja();
  Zdarzenie* wykonaj(Siec &siec);
  double Czas() const;
  int ZwrocId()const;
  int Priorytet() const;
private:
  double czas_nastepnego_;
  double czas_zdarzenia_;
  double czas_konca_;
  int id_;
  int priorytet_;
  Generator *ctp_;
  Generator *cgp_;
};
#endif
