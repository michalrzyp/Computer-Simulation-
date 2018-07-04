#ifndef PAKIET_H_
#define PAKIET_H_
#include"protokol.h"
class Pakiet
{
public:
  Pakiet(double czas_wystapienia, int CTP);
  ~Pakiet();
  double Czas() const;
  int ZwrocCtp();
  int ZwrockCtiz() const;
  bool CzyRetransmisja();
  void Retransmisja(bool stan);
  void ZwiekszLiczbeRetransmisji();
  int ZwrocLiczbeRetransmisji();
  Protokol* CsmaCa();
  bool CzyOpozniony();
  void UstawOpoznienie(bool stan);
private:
  const int kCtiz_ = 1;//CTIZ czas transmisji ACK =1ms
  int ctp_;//zmienna losowa reprezentuj¹ca czas transmisji wiadomoœci ze stacji nadawczej do odbiorczej
  double czas_;//czas wystapienia pakietu
  bool retransmisja_;//czy wystapila retransmisja
  int liczba_retransmisji_;
  bool opoznienie_;//flaga informujaca czy nastapi opoznianie pakietu o czas BT
  Protokol *csma_ca_;
};
#endif //PAKIET_H_