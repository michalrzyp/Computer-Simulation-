#ifndef ZAPIS_H_
#define ZAPIS_H_

#include <fstream>
#include <Windows.h>
using namespace std;
class Zapis
{
public:
  enum Message_
  {
    kGeneracja,
    kNasluch,
    kTransmisja,
    kAck,
    kZakonczenieTransmisji,
    kKolizja,
    kRetransmisja,
    kOdbior,
    kOpoznienie
  };
  Zapis(bool tryb);
  ~Zapis();
  void WriteLog(Message_ msg, double time,int id);
private:
  bool tryb_krokowy_;
  ofstream logfile_;
  HANDLE hOut_;
};
#endif // !NETWORK_SIMULATION_LOGGER_H