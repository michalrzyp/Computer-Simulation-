#ifndef KOLIZJA_H_
#define KOLIZJA_H_
#include"siec.h"
class Kolizja
{
public:
  Kolizja(int id);
  ~Kolizja();
  bool wykonaj(Siec &siec);
private:
  double czas_;
  int id_;
};
#endif
