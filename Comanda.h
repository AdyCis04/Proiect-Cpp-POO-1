#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"

class Comanda {
protected:
    const int id;
    int zi, luna, an;             // Data comenzii
    int nrProduse;                // Numarul total de produse din comanda
    Produs* produse;              // Vector alocat dinamic pentru produsele din comanda

public:
    Comanda(int, int, int, int, int, Produs*); // constructorul Comanda
    Comanda();  // Constructorul default al clasei Comanda
    ~Comanda(); // Destructorul clasei Comanda


    int get_id() const;
    int get_zi() const;
    int get_luna() const;
    int get_an() const;
    int get_nrProduse() const;
    Produs*& get_produse(); // Returneaza vectorul produse

    // TODO: de implementat
};

#endif
