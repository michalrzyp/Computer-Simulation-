#ifndef KALENDARZ_H_
#define KALENDARZ_H_
#include <queue>
#include"zdarzenie.h"
//#include"pakiet.h"

struct CompareNode : public std::binary_function<Zdarzenie*, Zdarzenie*, bool>
{
  bool operator()(const Zdarzenie* lhs, const Zdarzenie* rhs) const;
};
//Zbior wszystkich pakietow w sieci
class Kalendarz
{
public:
  Kalendarz();
  ~Kalendarz();
  void DodajZdarzenie(Zdarzenie *nowy);
  void UsunZdarzenie();
  Zdarzenie* ZdejmijZdarzenie();
  bool Pusty();
private:
  std::priority_queue<Zdarzenie*, std::vector<Zdarzenie*>, CompareNode> kalendarz_;
};
#endif
