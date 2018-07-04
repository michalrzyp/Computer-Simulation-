#ifndef PROTOKOL_H_
#define PROTOKOL_H_
class Generator;
class Protokol
{
public:
  Protokol();
  ~Protokol();
  void UstawDifs(double czas);
  void UstawBt(int czas);
  void UstawNoweCw();
  void UstawBt();
  void ZmniejszBt();
  void ZmniejszDifs();
  double ZwrocDifs();
  int ZwrocBt();
  int ZwrocCwMin();
  int ZwrocCwMax();
  int ZwrocCw();
private:
  double difs_;
  int cw_min_;
  int cw_max_;
  int cw_;
  int bt_;
  Generator *generator_bt_;
};
#endif