#include "kalendarz.h"

bool CompareNode::operator()(const Zdarzenie* lhs, const Zdarzenie* rhs) const
{
  if (lhs != nullptr && rhs != nullptr)
  {
    if (lhs->Czas() > rhs->Czas()) return true;
    if (lhs->Czas() < rhs->Czas()) return false;
    if (lhs->Priorytet() < rhs->Priorytet()) return true;
    if (lhs->Priorytet() > rhs->Priorytet()) return false;
    return false;
  }
  else
  {
    return false;
  }
  return lhs->Czas() > rhs->Czas();
}

Kalendarz::Kalendarz()
{
}

Kalendarz::~Kalendarz()
{
}

void Kalendarz::DodajZdarzenie(Zdarzenie *nowy)
{
  kalendarz_.push(nowy);
}

Zdarzenie* Kalendarz::ZdejmijZdarzenie()
{
  return kalendarz_.top();
}

void Kalendarz::UsunZdarzenie()
{
  kalendarz_.pop();
}
bool Kalendarz::Pusty()
{
  return kalendarz_.empty();
}