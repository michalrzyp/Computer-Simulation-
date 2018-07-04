#ifndef ZDARZENIE_H_
#define ZDARZENIE_H_
struct Siec;
class Zdarzenie
{
public:
  Zdarzenie(double time);
  Zdarzenie();
  virtual ~Zdarzenie();
  virtual double Czas() const;
  virtual Zdarzenie* wykonaj(Siec &siec) = 0;
  virtual int ZwrocId()const;
  virtual int Priorytet() const = 0;
private:
  double czas_; // czas wystapienia zdarzenia 
  int id_;
  int priorytet_;
};
#endif

