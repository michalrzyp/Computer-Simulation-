#ifndef RETRANSMISJA_H_
#define RETRANSMISJA_H_
#include"siec.h"
class Retransmisja
{
public:
  Retransmisja(int id);
  ~Retransmisja();
  bool wykonaj(Siec &siec);
private:
  int licznik_;
  double czas_;
  int id_;
};
#endif

