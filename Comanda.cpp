#include "Comanda.h"
#include <iostream>
#include <cstring>

Comanda::Comanda(int id, int zi, int luna, int an, int nrProduse, Produs* produse): id(id)
{
    this->zi=zi;
    this->luna=luna;
    this->an=an;
    this->nrProduse=nrProduse;

    this->produse=new Produs[nrProduse];

    //In for-ul de mai jos am copiat datele despre fiecare produs transmis prin parametrul de intrare Produs* produse
    //fara sa dau mai departe adresele fiecarui element din vector.
    for (int i=0;i<nrProduse;i++)
    {
        new (&(this->produse[i])) Produs(produse[i].get_id(),produse[i].get_denumire(),produse[i].get_pret(),produse[i].get_cantitate());
    }
}

Comanda::Comanda(): id(0), zi(0), luna(0), an(0), nrProduse(0), produse(nullptr) {}

Comanda::~Comanda()
{
    delete[] produse;
    produse = nullptr;
}

int Comanda::get_id() const
{
    return id;
}

int Comanda::get_zi() const
{
    return zi;
}

int Comanda::get_luna() const
{
    return luna;
}

int Comanda::get_an() const
{
    return an;
}

int Comanda::get_nrProduse() const
{
    return nrProduse;
}

Produs*& Comanda::get_produse()
{
    // Returnam vectorul de produse
    return produse;
}

//implementare clasa Comanda