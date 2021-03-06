#ifndef KANAL_H_
#define KANAL_H_
#include <vector>
class Pakiet;
struct Kanal
{
  Kanal();
  ~Kanal();
  bool stan_kanalu_;//zmienna określająca stan kanału
  int liczba_pakietow_;//liczba pakietow bedaca w kanale do wykrywania kolizji jesli nadane w tym samym czasie
  int id_;//zmienna identyfikująca nadajnik i odbiornik ktore aktualnie zajmuja kanal
  bool kolizja_;//zmienna informujaca o wystapieniu kolizji
  std::vector<Pakiet*> bufor_aktualnych_;
  double max_czas_zajetosci_;
};
#endif //KANAL_H_