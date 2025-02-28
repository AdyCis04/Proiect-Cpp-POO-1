#ifndef CLIENT_H
#define CLIENT_H

#include "Comanda.h"

class Client {
private:
    char nume[60];  // Numele clientului
    Comanda comanda; //comanda clientului

public:
    // TODO: de implementat
    Client();
    Client(const char*, Comanda);

    const char* get_nume() const;
    Comanda& get_comanda();

    void set_nume(const char*);
    void set_comanda(int, int, int, int, int, Produs*); // Schimba valorile parametrilor comenzii clientului
};

#endif
