#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <cstring>

class Produs {
    const int id;           // Cod unic al produsului
    char denumire[50];      // Denumirea produsului (șir de caractere)
    float pret;             // Prețul produsului
    int cantitate;          // Cantitatea pe stoc a produsului

public:
    Produs(); // Constructorul default
    Produs(int, const char*, float, int); // Constructorul clasei Produs

    int get_id() const;
    const char* get_denumire() const;
    float get_pret() const;
    int get_cantitate() const;

    void set_denumire(const char*);
    void set_cantitate(int);
    void set_pret(float);


    friend std::istream& operator>>(std::istream&, Produs&);
    friend std::ostream& operator<<(std::ostream&, const Produs&);
    // TODO: de implementat
};

#endif
