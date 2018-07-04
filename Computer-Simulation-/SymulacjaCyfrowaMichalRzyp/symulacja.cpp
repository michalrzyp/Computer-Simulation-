#include "symulacja.h"
#include<iostream>
#include <math.h>
#include"statystyki.h"
using namespace std;

Symulacja::Symulacja(int liczba_symulacji, int faza_poczatkowa, double czas_symulacji, bool tryb, double lambda)
{
  tryb_krokowy_ = tryb;
  lambda_ = lambda;
  faza_poczatkowa_ = faza_poczatkowa;
  czas_konca_ = czas_symulacji;
  liczba_symulacji_ = liczba_symulacji;

  ifstream file;//plik wejscia
  file.open("tablica_ziaren.txt");
  if (!file)
    std::cout << "Nie udalo sie otworzy pliku ziarna.txt" << std::endl;
  double tmp;
  for (int i = 0; i < Ziarna; ++i)
  {
    file >> tmp;
    tablica_ziaren_[i] = tmp;
  }
  file.close();
}

Symulacja::~Symulacja()
{
  delete CTP;
  for (int i = 0; i < l_urzadzen; ++i)
    delete CGP[i];
}

void Symulacja::run()
{
  Zdarzenie *generacja[l_urzadzen];
  for (int k = 0; k < l_urzadzen; ++k)
  {
    generacja[k] = nullptr;
  }
  double srednia_bledy = 0.0;
  double srednia_przep = 0.0;
  double czas[l_urzadzen] = { 0.0 };
  for (int i = 0; i < liczba_symulacji_; ++i)
  {
    Siec *siec_ = new Siec(tryb_krokowy_, i);

    Zdarzenie *aktualne = nullptr;
    Zdarzenie *nowe = nullptr;

    Statystyki::ilosc_pakietow_ = 0;
    Statystyki::ilosc_odebrana_ = 0;
    Statystyki::liczba_straconych_ = 0;
    Statystyki::max_stopa_bledu_ = 0.0;
    Statystyki::srednia_stopa_bledow_ = 0.0;
    Statystyki::liczba_retransmisji_ = 0.0;
    Statystyki::opoznienie_ = 0.0;
    Statystyki::oczekiwanie_ = 0.0;
    for (int m = 0; m < l_urzadzen; m++)
    {
      Statystyki::stopy_bledow_[m] = 0.0;
      Statystyki::odebrane_na_odbiornik[m] = 0;
      Statystyki::stracone_na_nadajnik[m] = 0;
    }
    Statystyki::faza_poczatkowa_ = faza_poczatkowa_;

    for (int j = 0; j < l_urzadzen; ++j)
    {
      CGP[j] = new Generator(tablica_ziaren_[j + (i * 13)], lambda_);//Stworzenie dla kazdego nadajnika generatora
      //Zaokraglenie do dziesiatej czesci milisekundy
      czas[j] = CGP[j]->RozkladWykladniczy();
      czas[j] = floor(czas[j] * 10);
      czas[j] /= 10;
    }

    CTP = new Generator(tablica_ziaren_[12 + (i * 13)], lambda_);

    for (int k = 0; k < l_urzadzen; ++k)
    {
      generacja[k] = new Generacja(czas[k], k, CTP, CGP[k], czas_konca_);//Inicjacja poczatkowych zdarzen 
      siec_->terminarz_.DodajZdarzenie(generacja[k]);
    }

    WyslanieACK *potwierdzenie;
    Kolizja *kolizja;
    Retransmisja *retransmisja;

    bool flaga[3];
    for (int n = 0; n < 3; n++) flaga[n] = true;
    while (siec_->czas_symulacji_ < czas_konca_)
    {
      if (siec_->terminarz_.Pusty() == false)
      {
        aktualne = siec_->terminarz_.ZdejmijZdarzenie();
        siec_->czas_symulacji_ = aktualne->Czas();
        siec_->terminarz_.UsunZdarzenie();
        nowe = aktualne->wykonaj(*siec_);

        potwierdzenie = new WyslanieACK(aktualne->ZwrocId());
        kolizja = new Kolizja(aktualne->ZwrocId());
        retransmisja = new Retransmisja(aktualne->ZwrocId());

        if (nowe != nullptr)
        {
          while (flaga[0] == true || flaga[1] == true || flaga[2] == true)
          {
            flaga[0] = potwierdzenie->wykonaj(*siec_);
            flaga[1] = kolizja->wykonaj(*siec_);
            flaga[2] = retransmisja->wykonaj(*siec_);
          }
          siec_->terminarz_.DodajZdarzenie(nowe);
          for (int n = 0; n < 3; n++) flaga[n] = true;
        }
        delete potwierdzenie;
        potwierdzenie = nullptr;
        delete kolizja;
        kolizja = nullptr;
        delete retransmisja;
        retransmisja = nullptr;
      }
    }
    for (int l = 0; l < 12; ++l)
    {
      Statystyki::stopy_bledow_[l] = (Statystyki::stracone_na_nadajnik[l] / (Statystyki::stracone_na_nadajnik[l] + Statystyki::odebrane_na_odbiornik[l]));

      Statystyki::srednia_stopa_bledow_ += Statystyki::stopy_bledow_[l];

      if (Statystyki::max_stopa_bledu_ <= Statystyki::stopy_bledow_[l])
        Statystyki::max_stopa_bledu_ = Statystyki::stopy_bledow_[l];
    }
    cout << endl;
    log_.open("statystyki.txt", ios::out | ios::app);

    cout << "Symulacja nr: " << i + 1 << endl;
    log_ << "Symulacja nr: " << i + 1 << endl;;
    cout << "Liczba pakietow: " << Statystyki::ilosc_pakietow_ << endl;
    cout << "Liczba pakietow odebranych: " << Statystyki::ilosc_odebrana_ << endl;
    cout << "Liczba pakietow straconych: " << Statystyki::liczba_straconych_ << endl;
    cout << "Liczba retransmisji: " << Statystyki::liczba_retransmisji_ << endl;
    cout << "Odebrane do straconych: " << (Statystyki::ilosc_odebrana_*100.0 / (Statystyki::liczba_straconych_ + Statystyki::ilosc_odebrana_)) << "%" << endl;
    cout << "Odebrane do nadanych: " << (Statystyki::ilosc_odebrana_*100.0 / Statystyki::ilosc_pakietow_) << "%" << endl;
    cout << endl;

    cout << "Srednia pakietowa stopa bledow: " << Statystyki::srednia_stopa_bledow_ / l_urzadzen << endl;
    log_ << "Srednia pakietowa stopa bledow: " << Statystyki::srednia_stopa_bledow_ / l_urzadzen << endl;
    cout << "Maksymalna pakietowa stopa bledow: " << Statystyki::max_stopa_bledu_ << endl;
    log_ << "Maksymalna pakietowa stopa bledow: " << Statystyki::max_stopa_bledu_ << endl;
    cout << "Przeplywnosc systemu: " << Statystyki::ilosc_odebrana_ / (czas_konca_ / 1000.0) << " pakietow na sekunde" << endl;
    log_ << "Przeplywnosc systemu: " << Statystyki::ilosc_odebrana_ / (czas_konca_ / 1000.0) << " pakietow na sekunde" << endl;
    cout << "Srednie opoznienie pakietu: " << Statystyki::opoznienie_ / Statystyki::ilosc_odebrana_ << " ms" << endl;
    cout << "Sredni czas oczekiwania pakietu: " << Statystyki::oczekiwanie_ / Statystyki::ilosc_odebrana_ << " ms" << endl;
    cout << "Srednia liczba retransmisji: " << Statystyki::liczba_retransmisji_ / Statystyki::ilosc_odebrana_ << endl;
    log_.close();
    srednia_bledy += Statystyki::srednia_stopa_bledow_ / l_urzadzen;
    srednia_przep += Statystyki::ilosc_odebrana_ / (czas_konca_ / 1000.0);
    delete potwierdzenie;
    delete kolizja;
    delete retransmisja;
    delete aktualne;
    delete nowe;
    delete siec_;
    for (int k = 0; k < l_urzadzen; ++k)
      generacja[k] = nullptr;
    siec_ = nullptr;
  }
  cout << "Srednia stopa bledow na 12 symulacji= " << srednia_bledy / 12.0 << endl;
  cout << "Srednia przeplywnosc na 12 symulacji= " << srednia_przep / 12.0 << endl;
  for (int k = 0; k < l_urzadzen; ++k)
    delete generacja[k];
}