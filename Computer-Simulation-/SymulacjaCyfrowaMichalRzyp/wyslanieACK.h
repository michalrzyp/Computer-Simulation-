#ifndef WYSLANIEACK_H_
#define WYSLANIEACK_H_
#include"siec.h"
class WyslanieACK
{
public:
  WyslanieACK(int id);
  ~WyslanieACK();
  bool wykonaj(Siec &siec);
private:
  double czas_;
  int numer_odbiornika_;
};
#endif

