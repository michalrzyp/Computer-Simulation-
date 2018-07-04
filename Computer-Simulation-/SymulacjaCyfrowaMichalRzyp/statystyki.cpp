#include "statystyki.h"

Statystyki::Statystyki()
{
}

Statystyki::~Statystyki()
{
}

int Statystyki::ilosc_pakietow_ = 0;
int Statystyki::ilosc_odebrana_ = 0;
int Statystyki::liczba_straconych_ = 0;
double Statystyki::max_stopa_bledu_ = 0.0;
double Statystyki::srednia_stopa_bledow_ = 0.0;
double Statystyki::liczba_retransmisji_ = 0.0;
double Statystyki::opoznienie_ = 0.0;
double Statystyki::oczekiwanie_ = 0.0;
double Statystyki::stopy_bledow_[12] = { 0.0 };
double Statystyki::odebrane_na_odbiornik[12] = { 0 };
double Statystyki::stracone_na_nadajnik[12] = { 0 };
int Statystyki::faza_poczatkowa_ = 0;
