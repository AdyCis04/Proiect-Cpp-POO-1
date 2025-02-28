#include "Client.h"
#include <iostream>
#include <cstring>

Client::Client(): comanda()
{
    nume[0]='\0';
}
Client::Client(const char* nume, Comanda comanda): comanda(comanda)
{
    strncpy(this->nume,nume,sizeof(this->nume));
    this->nume[sizeof(this->nume)-1]='\0';
}

const char* Client::get_nume() const
{
    return nume;
}

Comanda& Client::get_comanda()
{
    return comanda;
}

void Client::set_nume(const char* nume)
{
    strncpy(this->nume,nume,sizeof(this->nume));
    this->nume[sizeof(this->nume)-1]='\0';
}

void Client::set_comanda(int id, int zi, int luna, int an, int nrProduse, Produs* produse)
{
    new (&comanda) Comanda(id,zi,luna,an,nrProduse,produse);
    // Stocam valorile pentru parametrii comenzii in spatiul de memorie alocat parametrului comanda din obiectul de clasa Client.
}

//implementare clasa Client