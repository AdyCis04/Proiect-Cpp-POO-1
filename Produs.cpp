#include "Produs.h"
#include <iostream>
#include <cstring>

Produs::Produs(): id(0), pret(0.0), cantitate(0)
{
    denumire[0]='\0';
}

Produs::Produs(int id, const char* denumire, float pret, int cantitate): id(id), pret(pret), cantitate(cantitate)
{
    strncpy(this->denumire,denumire,sizeof(this->denumire));
    this->denumire[sizeof(this->denumire)-1]='\0';
}

int Produs::get_id() const
{
    return id;
}

int Produs::get_cantitate() const
{
    return cantitate;
}

float Produs::get_pret() const
{
    return pret;
}

const char* Produs::get_denumire() const
{
    return denumire;
}

std::istream& operator>>(std::istream& in, Produs& object)
{
    in >> object.denumire >> object.pret >> object.cantitate;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Produs& object)
{
    out << object.get_id() << ". " << object.get_denumire() << ": " << object.get_cantitate() << ", Pret: " << object.get_pret();
    return out;
}

void Produs::set_denumire(const char* denumire)
{
    strncpy(this->denumire, denumire, sizeof(this->denumire));
    this->denumire[sizeof(this->denumire)-1]='\0';
}

void Produs::set_cantitate(int cantitate)
{
    this->cantitate=cantitate;
}

void Produs::set_pret(float pret)
{
    this->pret=pret;
}

//implementare clasa Produs