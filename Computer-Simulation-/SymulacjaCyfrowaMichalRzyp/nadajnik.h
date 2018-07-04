#ifndef NADAJNIK_H_
#define NADAJNIK_H_

#include <queue>
#include"pakiet.h"
class Nadajnik
{
public:
  Nadajnik(int id);
  ~Nadajnik();
  void DodajPakiet(Pakiet *pakiet);
  bool Pusty();
  int ZwrocId();
  Pakiet* ZdejmijPakiet();
  void UstawPotwierdzenie(bool stan);
  bool Potwierdzenie();
  void UsunPakiet();
  bool CzyWyslac();
  void ZezwolWyslac(bool status);
private:
  int id_nadajnika_; //identyfikacjê nadajnika
  std::queue<Pakiet*> bufor_; //bufor jako kolejka FIFO do trzymania pakietow
  bool potwierdzenie_;
  bool status_;// zezwolenie na wyslanie
};

#endif //NADAJNIK_H_