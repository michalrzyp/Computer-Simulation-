#ifndef ODBIORNIK_H_
#define ODBIORNIK_H_
#include"pakiet.h"
class Odbiornik
{
public:
  Odbiornik(int id);
  ~Odbiornik();
  bool Ack();
  void UstawAck(bool stan);//ustawienie zmiennej w przypadku poprawnie odebranego pakietu
  int ZwrocId();
  Pakiet* ZwrocPakiet();
  void UstawBiezacyPakiet(Pakiet* a);
private:
  int id_odbiornika_;//identyfikacji odbiornika 
  bool ack_;//zmienna informuj¹ca o poprawnym odebraniu
  Pakiet *aktualny;
};

#endif //ODBIORNIK_H_