#include "Zapis.h"
#include <iostream>
#define niebieski 9
#define zielony 10
#define jasnoniebieski 11
#define czerwony 12
#define rozowy 13
#define zolty 14
#define bialy 15
using namespace std;

Zapis::Zapis(bool tryb)
{
  logfile_.open("www.txt", ios::out | ios::trunc);
  if (!logfile_)
    cout << "Nie udalo sie otworzy pliku www.txt" << endl;
  logfile_ << flush;
  logfile_.close();
  tryb_krokowy_ = tryb;
  hOut_ = GetStdHandle(STD_OUTPUT_HANDLE);
}
Zapis::~Zapis()
{
}

void Zapis::WriteLog(Message_ msg, double time, int id)
{
  if (tryb_krokowy_ == true)
  {
    logfile_.open("www.txt", ios::out | ios::app);
    switch (msg)
    {
    case kGeneracja:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), niebieski);
      cout << "Generacja pakietu w czasie: " << time << " w nadajniku nr: " << id << endl;
      logfile_ << "Generacja pakietu w czasie: " << time << " w nadajniku nr: " << id << endl;

      break;
    case kNasluch:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), zielony);
      cout << "---Kanal wolny---   Nadajnik nr: " << id << endl;
      //logfile_ << "---Kanal wolny---   Nadajnik nr: " << id << endl;

      break;
    case kZakonczenieTransmisji:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), jasnoniebieski);
      cout << "Odebrano ACK, koniec transmisji w czasie: " << time << " z nadajnika nr: " << id << endl;
      logfile_ << "Odebrano ACK, koniec transmisji w czasie: " << time << " z nadajnika nr: " << id << endl;

      break;
    case kOdbior:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rozowy);
      cout << "Odebrano pakiet w czasie: " << time << " z nadajnika nr: " << id << endl;
      logfile_ << "Odebrano pakiet w czasie: " << time << " z nadajnika nr: " << id << endl;

      break;
    case kTransmisja:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bialy);
      cout << "Transmisja w czasie: " << time << " z nadajnika nr: " << id << endl;
      logfile_ << "Transmisja w czasie: " << time << " z nadajnika nr: " << id << endl;

      break;
    case kAck:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), zolty);
      cout << "Wysylanie ACK w czasie: " << time << " z odbiornika nr: " << id << endl;
      logfile_ << "Wysylanie ACK w czasie: " << time << " z odbiornika nr: " << id << endl;

      break;
    case kKolizja:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), czerwony);
      cout << "Kolizja w czasie: " << time << endl;
      logfile_ << "Kolizja w czasie: " << time << endl;

      break;
    case kOpoznienie:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bialy);
      cout << "Opoznianie pakietu z nadajnika nr: " << id << endl;
      logfile_ << "Opoznianie pakietu z nadajnika nr: " << id << endl;

      break;
    case kRetransmisja:
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bialy);
      cout << "ACK nie doszlo, retransmisja w czasie: " << time << " Nadajnik nr: " << id << endl;
      logfile_ << "ACK nie doszlo, retransmisja w czasie: " << time << " Nadajnik nr: " << id << endl;
      break;
    default:
      break;
    }
    logfile_.close();
    if (tryb_krokowy_ == true) system("pause"); cout << endl;
  }
}