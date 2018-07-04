#ifndef STATYSTYKI_H_
#define STATYSTYKI_H_
struct Statystyki
{
  Statystyki();
  ~Statystyki();
  static int ilosc_pakietow_;
  static int ilosc_odebrana_;
  static int liczba_straconych_;
  static double max_stopa_bledu_;
  static double srednia_stopa_bledow_;
  static double liczba_retransmisji_;
  static double opoznienie_;
  static double oczekiwanie_;
  static double stopy_bledow_[12];
  static double stracone_na_nadajnik[12];
  static double odebrane_na_odbiornik[12];
  static int faza_poczatkowa_;
};
#endif

